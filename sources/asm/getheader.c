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

static void istherebrac(char *s, list_t *list)
{
	while (*s)
	{
		if (*s == COMMENT_CHAR)
			break ;
		if (*s == '\"')
			return ;
		s++;
	}
	error(list, "no \", sorry");
}

static void betweenbrac(char *s, char *assign, list_t *list)
{
	int len;

	len = -1;
	istherebrac(s, list);
	while (*s != '\"')
		s++;
	s++;
	while (s[++len] != '\"')
		;
	istherebrac(s, list);
	ft_strncpy(assign, s, len);
}

static int getname(char *s, list_t *list, char *assign)
{
	int i;
	int j;
	int len;

	i = -1;
	len = ft_strlen(LABEL_CHARS);
	while (s[++i])
	{
		list->y += 1;
		j = -1;
		if (s[i] == COMMENT_CHAR)
			break ;
		while (LABEL_CHARS[++j])
			if (LABEL_CHARS[j] == s[i])
				break ;
		if (j == len)
			break ;
	}
	betweenbrac(s + i, assign, list);
	return (i);
}

static void checkend(char *s, list_t *list)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == COMMENT_CHAR)
			break ;
}

list_t *getheader(int fd, list_t *list)
{
	int		i;
	int		len;

	list->type = 0;
	list->line = skipnl(fd, list);
	i = skipsp(list->line, list);
	len = ft_strlen(NAME_CMD_STRING);
	if (ft_strncmp(list->line + i, NAME_CMD_STRING, len))
		error(list, "name error\n");
	list->y += (i += len);
	getname(list->line + i, list, list->name);
	checkend(list->line + i, list);
	freeline(&(list->line));
	list->line = skipnl(fd, list);
	i = skipsp(list->line, list);
	len = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strncmp(list->line + i, COMMENT_CMD_STRING, len))
		error(list, "comment error\n");
	list->y += (i += len);
	getname(list->line + i, list, list->comment);
	checkend(list->line + i, list);
	freeline(&(list->line));
	return (newlink(list));
}
