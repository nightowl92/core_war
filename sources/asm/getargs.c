/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:02:22 by stherkil          #+#    #+#             */
/*   Updated: 2020/02/29 15:51:01 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int isnum(char *s)
{
	while (*s && *s > ' ')
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static  int getarg(char *s)
{
	if (*s == 'r')
	{
		//register
	}
	else if (*s == '%')
	{
		//direct
	}
	else if (isnum(s))
		//indirect
	else
		return (0);
}

int 	getargs(char *s, list_t *list)
{
	if (!getarg(s))
		error(list);
}
