/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:48:23 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/27 20:32:44 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"
#include "corewar.h"

int		main(int ac, char **av)
{
	t_data		data;

	op_bzero(&data, sizeof(t_data));
	init(&data, ac, av);
	printf("checkpoint 1\n");
	battle(&data);
	printf("checkpoint 3\n");
	show_mars(&data);
	printf("%d ", data.champs->fd);

	printf("%s ", data.champs->prog_name);
	return (0);
}
