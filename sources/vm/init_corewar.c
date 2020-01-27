/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:08:38 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/27 21:17:57 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

int		mars_fill(t_data *data)
{
	int		i;
	t_champ	*champ;
	int		offset;

	champ = data->champs;
	offset = 0;
	while (champ)
	{
		i = 0;
		while (i < CHAMP_MAX_SIZE)
		{
			data->mars[offset + i] = champ->content[i];
			i++;
		}
		champ = champ->next;
		offset += CHAMP_MAX_SIZE / data->nbr_champs;
	}
	return (0);
}

int		init(t_data *data, int ac, char **av)
{
	int		id;

	id = 1;
	if (ac == -1 || av == 0)
		return (0);
	*(int *)data->mars = 0xabcdef10;
	new_champ(data, av[1], id);
	new_champ(data, av[2], id);
	mars_fill(data);
	return (0);
}

