/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:48:23 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/23 20:20:44 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

int		init(t_data *data, int ac, char **av)
{
	if (ac == -1 || av == 0)
		return (0);
	*(int *)data->mars = 0xabcdef10;
	return (0);
}

int		main(int ac, char **av)
{
	t_data		data;

	init(&data, ac, av);
	battle(&data);
	show_mars(&data);
	return (0);
}
