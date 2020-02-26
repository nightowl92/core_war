/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:19:42 by vlaroque          #+#    #+#             */
/*   Updated: 2020/02/26 13:25:14 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"
#include <unistd.h>

int		execute_operation()
{
	return (0);
}

int		new_turn(t_data *data)
{
	t_process	*process;

	process = data->processes;
	while (process)
	{
		if (process->cooldown > 1)
			process->cooldown--;
		else if (process->cooldown == 1)
			execute_operation();
		else if (read_operation(data, process))
			;
		else
			process->pc = (process->pc + 1) % MEM_SIZE;
		process = process->next;
	}
	return (0);
}

int		battle(t_data *data)
{
	int		turn;

	turn = 0;
	write(1, "\e[2J", 4);
	while (1)
	{
		new_turn(data);
		if (turn > 100000)
			return (1);
//		show_mars(data);
		buff_mars(data);
		ft_putstr("\n\n");
		turn++;
	}
	return (0);
}
