/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:26:23 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/30 21:26:46 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "corewar.h"

int			new_process(t_data *data, int loc, int reg_one)
{
	t_process		*process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (-1);
	op_bzero(process, sizeof(t_process));
	if (data->processes)
		process->next = data->processes;
	data->processes = process;


}
