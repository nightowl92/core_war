/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:14:39 by vlaroque          #+#    #+#             */
/*   Updated: 2020/03/07 05:54:51 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

int		op_live(t_data *data, t_process *process)
{
	process->life = 1;
	data->lives++;
	if (data->lives == NBR_LIVE)
	{
		data->lives = 0;
		if (data->max_cycles > 0)
			data->max_cycles -= CYCLE_DELTA;
	}
	return (0);
}

int		op_ld(t_data *data, t_process *process)
{
	return (0);
}

int		op_st(t_data *data, t_process *process)
{
	return (0);
}

int		op_add(t_data *data, t_process *process)
{
	return (0);
}

int		op_sub(t_data *data, t_process *process)
{
	return (0);
}

int		op_and(t_data *data, t_process *process)
{
	return (0);
}

int		op_or(t_data *data, t_process *process)
{
	return (0);
}

int		op_xor(t_data *data, t_process *process)
{
	return (0);
}

int		op_zjmp(t_data *data, t_process *process)
{
	return (0);
}

int		op_ldi(t_data *data, t_process *process)
{
	return (0);
}

int		op_sti(t_data *data, t_process *process)
{
	return (0);
}

int		op_fork(t_data *data, t_process *process)
{
	return (0);
}

int		op_lld(t_data *data, t_process *process)
{
	return (0);
}

int		op_lldi(t_data *data, t_process *process)
{
	return (0);
}

int		op_lfork(t_data *data, t_process *process)
{
	return (0);
}

int		op_aff(t_data *data, t_process *process)
{
	return (0);
}
