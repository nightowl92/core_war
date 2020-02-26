/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:01:15 by vlaroque          #+#    #+#             */
/*   Updated: 2020/02/19 10:11:08 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"
#include "../common/op.c"

int		get_encoding_byte(t_data *data, t_process *process)
{

}

int		get_op(t_data *data, t_process *process)
{
	int		operation;

	operation = 0;
	while (op_tab[operation].op_code != 0)
	{
		if (op_tab[operation].op_code == data->mars[process->pc])
		{
			process->instruction.op = op_tab[operation].op_code;
			return (operation);
		}
		operation++;
	}
	return (-1);
}

int			read_operation(t_data *data, t_process *process)
{
	int		op_id;
	int		pc;

	op_id =  get_op(data, process);
	pc = process->pc;
	if (op_id < 0)
		return (-1);
	pc++;
	if (op_tab[op_id].encoding_byte)
	{
		pc++;
		get_encoding_byte(data, process	);
	}
	return (0);
}
