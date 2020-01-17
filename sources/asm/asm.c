/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:02:22 by stherkil          #+#    #+#             */
/*   Updated: 2019/12/15 16:29:57 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int	main(int argc, char **argv)
{
	header_t *header;

	header = NULL;
	if (argc != 2)
		errorparser("not enough arguments", header);
	if (ft_strrchr(argv[1], '.') && ft_strcmp(ft_strrchr(argv[1], '.'), ".s")
	&& ft_strcmp(ft_strrchr(argv[1], '.'), ".cor"))
			errorparser("only .s or .cor", header);
	if (!ft_strcmp(ft_strrchr(argv[1], '.'), ".cor"))
	{
		parserbit(argv[1], header);
	}
	else
	{
		;
	}
	return (0);
}