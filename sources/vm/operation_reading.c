/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:01:15 by vlaroque          #+#    #+#             */
/*   Updated: 2020/02/26 16:12:35 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"
#include "../common/op.c"

int		fill_arg(t_arg *arg, t_octet bits, int direct_size_two)
{
	if (bits == 1)
	{
		arg->type = T_REG;
		arg->len = 1;
	}
	else if (bits == 2)
	{
		arg->type = T_DIR;
		if (direct_size_two)
			arg->len = 2;
		else
			arg->len = 4;
	}
	else if (bits == 3)
	{
		arg->type = T_IND;
		arg->len = 2;
	}
	return (0);
}

int		get_encoding_byte(t_data *data, t_process *process, int *pc)
{
	int		arg_nbr;
	int		i;
	t_octet	encod;

	i = 0;
	arg_nbr = op_tab[process->instruction.op_id].param_number;
	process->instruction.encod = data->mars[*pc];
	encod = data->mars[*pc];
	while (arg_nbr)
	{
		fill_arg(&process->instruction.args[i], 3 & encod >> (3 - i), op_tab[process->instruction.op_id].direct_size_two);
		i++;
		arg_nbr--;
	}
	return (0);
}

int		get_op(t_data *data, t_process *process, int *pc)
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
	*pc++;
	return (-1);
}

int			read_operation(t_data *data, t_process *process)
{
	int		pc;

	pc = process->pc;
	process->instruction.op_id =  get_op(data, process, &pc);
	if (process->instruction.op_id < 0)
		return (0);
	pc++;
	if (op_tab[process->instruction.op_id].encoding_byte)
		get_encoding_byte(data, process, &pc);
	else
		//
	return (1);
}
