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

static int labellen(char *s)
{
	int i;

	i = -1;
	while (s[i])
	{
		if (s[i] == SEPARATOR_CHAR)
			break ;
		++i;
	}
	return (i);
}

static  int getarg(char *s, int *data, list_t *list, int *skip)
{
	int	lablen;
	int out;

	*skip = 2;
	if (*s == 'r')
	{
		out = ft_atoi(s + 1);
		*data = 1;
		if (out > 10)
			*skip = 3;
	}
	else if (*s == '%')
	{
		s = s + 1;
		if (*s == LABEL_CHAR)
		{
			s++;
			lablen = labellen(s);
			list->labelarg = ft_strnew(lablen);
			ft_strncpy(list->labelarg, s, lablen);
			*skip = lablen + 2;
		}
		else
		{
			out = ft_atoi(s + 1);
			*data = 3;
		}
	}
	else if (isnum(s))
	{
		out = ft_atoi(s);
		*data = 2;
	}
	else
		return (0);
	return (out);
}

static int skipinstr(list_t *list)
{
	if (list->ins == 1 || list->ins == 9 || list->ins == 12 || list->ins == 14)
		return (4);
	else if (list->ins == 15)
		return (5);
	else if (list->ins == 2 || list->ins == 3 || list->ins == 7)
		return (2);
	else
		return (3);
}

static char	*onearg(char *s, list_t *list, int nb, int islast)
{
	int data;
	int ret;
	int skip;

	list->args[nb] = getarg(s, &data, list, &skip);
	list->code = dohex(list->code, nb, data);
	s = s + skip;
	if (!islast)
		if (*s != SEPARATOR_CHAR || *s == COMMENT_CHAR)
			error(list, "no space\n");
	s += 1;
	s = s + skipsp(s, list);
	return (s);
}

int 	getargs(char *s, list_t *list)
{
	s = s + skipinstr(list);
	if (*s != ' ' || *s == COMMENT_CHAR)
		error(list, "no space\n");
	s = s + skipsp(s, list);
	s = onearg(s, list, 0, 0);
	s = onearg(s, list, 1, 0);
	s = onearg(s, list, 2, 1);
	return (1);
}
