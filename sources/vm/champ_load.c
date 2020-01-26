/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:52:08 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/26 18:38:42 by vlaroque         ###   ########.fr       */
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
	return (new);
}
/*
int		champ_fill(t_data *data, char *source)
{
	
}
*/
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
	
	
	return (1);
}
