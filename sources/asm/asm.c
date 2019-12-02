/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:02:22 by stherkil          #+#    #+#             */
/*   Updated: 2019/12/02 18:25:04 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (asmerror("not enough arguments"));
	if (ft_strrchr(argv[1], '.') && ft_strcmp(ft_strrchr(argv[1], '.'), ".s"))
			return (asmerror("only .s"));
	return (0);
}
