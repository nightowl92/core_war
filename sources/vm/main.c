/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:48:23 by vlaroque          #+#    #+#             */
/*   Updated: 2020/02/09 21:54:26 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "corewar.h"

int		main(int ac, char **av)
{
	t_data		data;

	op_bzero(&data, sizeof(t_data));
	init_corewar(&data, ac, av);
	mars_fill(&data);
	battle(&data);
	show_mars(&data);
	return (0);
}
