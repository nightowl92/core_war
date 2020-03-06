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

static int		*(func)(t_data *, t_process *)[17] = 
{op_live, op_ld, op_st, op_add, op_sub, op_and, op_or, op_xor, op_zjmp,
	op_ldi, op_sti, op_fork, op_lld, op_lldi, op_lfork, op_aff, NULL};

int		execute_operation(t_data *data, t_process *process)
{
	usleep(1000000);
	func[process->instruction->op_id](data, process);
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
			return (1 + err("end turn"));
		buff_mars(data);
		ft_putstr("Turn = "); ft_putnbr(turn); ft_putstr("  ");
		ft_putnbr(data->processes->cooldown);
		ft_putstr("           \n");
		new_turn(data);
		turn++;
	}
	return (0);
}
