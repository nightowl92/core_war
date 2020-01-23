/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:56:00 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/23 20:33:05 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "op.h"
#include "corewar.h"

void		char_hexa(t_octet c)
{
	char	base[] = "0123456789abcdef";
	
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

//128 64 32 16 8 4 2 1

int			show_mars(t_data *data)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
			write(1, "\n", 1);
		else if (i != 0)
			write(1, " ", 1);
		char_hexa(data->mars[i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
