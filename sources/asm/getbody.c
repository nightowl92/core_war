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

static int	instrnametonb2(char *s)
{
	if (!ft_strncmp("ldi", s, 3))
		return (10);
	else if (!ft_strncmp("sti", s, 3))
		return (11);
	else if (!ft_strncmp("fork", s, 4))
		return (12);
	else if (!ft_strncmp("lld", s, 3))
		return (13);
	else if (!ft_strncmp("lldi", s, 4))
		return (14);
	else if (!ft_strncmp("lfork", s, 5))
		return (15);
	else if (!ft_strncmp("aff", s, 3))
		return (16);
	else
		return (0);
}

static int	instrnametonb(char *s)
{
	if (!ft_strncmp("live", s, 4))
		return (1);
	else if (!ft_strncmp("ld", s, 2))
		return (2);
	else if (!ft_strncmp("st", s, 2))
		return (3);
	else if (!ft_strncmp("add", s, 3))
		return (4);
	else if (!ft_strncmp("sub", s, 3))
		return (5);
	else if (!ft_strncmp("and", s, 3))
		return (6);
	else if (!ft_strncmp("or", s, 2))
		return (7);
	else if (!ft_strncmp("xor", s, 3))
		return (8);
	else if (!ft_strncmp("zjmp", s, 4))
		return (9);
	else
		return (instrnametonb2(s));
}

static int	gettype(char *s, list_t *list)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == COMMENT_CHAR)
			break ;
		if (s[i] == LABEL_CHAR)
		{
			while (s[++i])
			{
				if (s[i] == COMMENT_CHAR)
					break ;
				if (s[i] > ' ')
					return (3);
				++i;
			}
			return (2);
		}
	}
	return (1);
}

static int	getlabel(char *s, list_t *list)
{
	int i;
	int j;
	int len;

	len = ft_strlen(LABEL_CHARS);
	i = -1;
	while (s[++i] != LABEL_CHAR)
	{
		j = -1;
		while (++j < len)
		{
			if (LABEL_CHARS[j] == s[i])
				break ;
			if (len == i)
				error(list, "label char not ok\n");
		}
	}
	if (!(list->label = ft_strnew(i)))
		error(list, "malloc error\n");
	ft_strncpy(list->label, s, i);
	return (i + 1);
}

list_t *getbody(int fd, list_t *list)
{
	int		i;
	int		len;

	if (!(list->line = skipnl(fd, list)))
		return (NULL);
	printf("line is %s\n", list->line);
	i = skipsp(list->line, list);
	if ((list->type = gettype(list->line + i, list)) == 2)
	{
		printf("you type is %d\n", list->type);
		if (!(list = getbody(fd, list)))
			error(list, "error arguments missing\n");
	}
	printf("lou type is %d\n", list->type);
	printf("1rest is %s $$ %d\n", list->line + i, i);
	if (list->type > 1)
		i += getlabel(list->line + i, list);
	i += skipsp(list->line + i, list);
	printf("2rest is %s $$ %d\n", list->line + i, i);
	if (!(list->ins = instrnametonb(list->line + i)))
		error(list, "error not instruction\n");
	//check if label
	return (newlink(list));
}
