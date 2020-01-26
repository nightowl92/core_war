/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:52:08 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/26 21:01:26 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "op.h"
#include "corewar.h"

unsigned int		big_little_endian(unsigned int nbr)
{
	unsigned int	new;
	t_octet			*ptr_nbr;
	t_octet			*ptr_new;

	ptr_nbr = (t_octet *) &nbr;
	ptr_new = (t_octet *) &new;
	ptr_new[0] = ptr_nbr[3];
	ptr_new[1] = ptr_nbr[2];
	ptr_new[2] = ptr_nbr[1];
	ptr_new[3] = ptr_nbr[0];
	printf("new = %d\n", new);
	return (new);
}

int		mars_fill(t_data *data)
{
	int		i;

	i = 0;
	while (i < CHAMP_MAX_SIZE)
	{
		data->mars[i] = data->champs->content[i];
		i++;
	}
	return (0);
}

int		champ_fill(t_champ *champ)
{
	t_octet			tmp[4];

	if (4 != read(champ->fd, &champ->magic_nbr, 4))
		return (-1);
//	if (champ->magic_nbr != COREWAR_EXEC_MAGIC)
////		return (-2);
	printf("lol\n");
	if (PROG_NAME_LENGTH != read(champ->fd, champ->prog_name, PROG_NAME_LENGTH))
		return (-3);
	if (4 != read(champ->fd, tmp, 4))
		return (-1);
	if (4 != read(champ->fd, tmp, 4))
		return (-1);
	champ->prog_size = big_little_endian(*(int *)(tmp));
	if (COMMENT_LENGTH != read(champ->fd, champ->comment, COMMENT_LENGTH))
		return (-3);
	if (4 != read(champ->fd, tmp, 4))
		return (-1);
	if (champ->prog_size != read(champ->fd, champ->content, champ->prog_size))
		return (-3);
	return (0);
}

int		champ_load(t_data *data, char *source)
{
	int		fd;
	t_champ	*champ;

	if (!(fd = open(source, O_RDONLY)))
		return (-1);
	if (!(champ = (t_champ *)malloc(sizeof(t_champ))))
		return (-1);
	op_bzero(champ, sizeof(t_champ));
	
	if (data->champs == champ)
		champ->next = data->champs;
	data->champs = champ;
	data->champs->fd = fd;
	champ_fill(champ);
	mars_fill(data);
	return (1);
}
