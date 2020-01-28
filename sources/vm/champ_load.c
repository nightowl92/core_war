/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:52:08 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/27 21:19:56 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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
	return (new);
}

int		champ_fill(t_champ *champ)
{
	t_octet			tmp[4];

	printf("champ fill = cp 0\n fd = %d\n", champ->fd);
	if (4 != read(champ->fd, tmp, 4))
		return (-1);
	printf("cp 1\n");
//	if (*(unsigned int *)tmp != big_little_endian(COREWAR_EXEC_MAGIC))
////		return (-2);
	printf("cp 2\n");
	if (PROG_NAME_LENGTH != read(champ->fd, champ->prog_name, PROG_NAME_LENGTH))
		return (-3);
	printf("cp 3\n");
	if (4 != read(champ->fd, tmp, 4))
		return (-1);
	printf("cp 4\n");
	if (4 != read(champ->fd, tmp, 4))
		return (-1);
	printf("cp 5\n");
	champ->prog_size = big_little_endian(*(int *)(tmp));
	printf("cp 6\n");
	if (COMMENT_LENGTH != read(champ->fd, champ->comment, COMMENT_LENGTH))
		return (-3);
	printf("cp 7\n");
	if (4 != read(champ->fd, tmp, 4))
		return (-1);
	printf("cp 8\n");
	if (champ->prog_size != read(champ->fd, champ->content, champ->prog_size))
		return (-3);
	printf("cp 9\n");
	return (0);
}

int		new_champ(t_data *data, char *source, int id)
{
	int		fd;
	t_champ	*champ;
	t_champ	*last;

	printf("new champ\n");
	fd = open(source, O_RDONLY);
	if (fd <= 0)
		return (-1);
	printf("fd = %d\n", fd);
	if (!(champ = (t_champ *)malloc(sizeof(t_champ))))
		return (-1);
	data->nbr_champs++;
	op_bzero(champ, sizeof(t_champ));
	champ->id = id;
	if (!data->champs)
		data->champs = champ;
	else
	{
		printf("second champ\n");
		last = data->champs;
		while (last->next)
			last = last->next;
		last->next = champ;
	}
	data->champs->fd = fd;
	printf("before fill\n");
	printf("fddd = %d\n", fd);
	champ_fill(champ);
	printf("end fill\n");
	close(fd);
	return (1);
}
