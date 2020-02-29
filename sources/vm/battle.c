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

int		execute_operation(t_data *data, t_process *process)
{
	process->cooldown--;
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
			execute_operation(data, process);
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
		if (turn > 100000)
			return (1);
		buff_mars(data);
		ft_putstr("\n");
		ft_putnbr(turn);
		ft_putstr("\n");
		ft_putnbr(data->processes->cooldown);
		ft_putstr("\n");
		new_turn(data);
		turn++;
	}
	return (0);
}
