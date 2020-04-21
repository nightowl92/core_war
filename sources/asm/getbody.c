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
		if (s[i] == LABEL_CHAR)
			break ;
	if (i == ft_strlen(s))
		error(list, "wrong format doesn't correspond to any type\n");
	while (s[i])
	{
		if (s[i] > 32)
			list->type = 3;
			return (i);
		++i;
	}
	list->type = 2;
	return (i);	
}

void getbody(int fd, list_t *list)
{
	int		i;
	int		len;

	list->line = skipnl(fd, list);
	i = skipsp(list->line, list);
	list->type = 1;
	if (!(list->ins = instrnametonb(list->line + i)))
		i = gettype(list->line + i, list);
}