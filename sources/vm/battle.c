/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:19:42 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/23 20:36:27 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

int		new_turn(t_data *data)
{
	void *ptr = (void *)data;
	ptr = 0;
	return (0);
}

int		battle(t_data *data)
{
	int		turn;

	turn = 0;
	while (1)
	{
		new_turn(data);
		if (turn > 100000)
			return (1);
		turn++;
	}
	return (0);
}
