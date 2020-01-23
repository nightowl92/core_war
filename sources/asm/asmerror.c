/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asmerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:07:11 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/20 11:46:40 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	errorparser(const char *s, header_t *header)
{
	if (header)
		free(header);
	ft_putendl(s);
	exit(0);
}