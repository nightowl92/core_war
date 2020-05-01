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

static  int getarg(char *s, int *data)
{
	int out;

	if (*s == 'r')
	{
		out = ft_atoi(s + 1);
		*data = 0;
	}
	else if (*s == '%')
	{
		out = ft_atoi(s + 1);
		*data = 2;
		//direct
	}
	else if (isnum(s))
	{
		out = ft_atoi(s);
		*data = 1;
	}
	//indirect
	else
		return (0);
}

int 	getargs(char *s, list_t *list)
{
	int data;
	int ret;

	if (!(list->args[0] = getarg(s, &data)))
		error(list, "problem\n");
	dohex(list->code, 0, data);

	list->args[1] = getarg(s, &data);
	if (list->args[1] && (list->ins == 1 || list->ins == 9 || list->ins == 12 || list->ins == 15))
		error(list, "problem\n");
	dohex(list->code, 1, data);

	if (!(list->args[2] = getarg(s, &data)))
		error(list);
	if (list->args[1] && (list->ins == 13 || list->ins == 16))
		error(list);
	dohex(list->code, 2, data);
}
