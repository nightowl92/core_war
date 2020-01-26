/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:48:23 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/26 21:02:38 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

int		init(t_data *data, int ac, char **av)
{
	if (ac == -1 || av == 0)
		return (0);
	*(int *)data->mars = 0xabcdef10;
	champ_load(data, av[1]);
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;

	init(&data, ac, av);
	battle(&data);
	show_mars(&data);
	printf("%d ", data.champs->fd);

	printf("%s ", data.champs->prog_name);
	return (0);
}
