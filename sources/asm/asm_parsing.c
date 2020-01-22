/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:01:42 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/22 13:46:40 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	asmparsing(header_t *header)
{
	unsigned char	BUF[2192];
	char *s;
	int ret;

	/*
		name
	*/
	if (get_next_line(header->fd, &s) > 0)
	{
		/* put exception if len not ok & progname length etc*/
		if (ft_strncmp(NAME_CMD_STRING, s, ft_strlen(NAME_CMD_STRING)))
			errorparser("name not ok", header);
		ft_strncpy(header->prog_name, s + ft_strlen(NAME_CMD_STRING) + 2, ft_strlen(s) - ft_strlen(NAME_CMD_STRING) - 3);
		free(s);
	}
	else
	{
		exit(0);
	}

	/*
		comment
	*/
	if (get_next_line(header->fd, &s) > 0)
	{
		/* put exception if len not ok & progname length etc*/
		if (ft_strncmp(COMMENT_CMD_STRING, s, ft_strlen(COMMENT_CMD_STRING)))
			errorparser("comment not ok", header);
		ft_strncpy(header->comment, s + ft_strlen(COMMENT_CMD_STRING) + 2, ft_strlen(s) - ft_strlen(COMMENT_CMD_STRING) - 3);
		free(s);
	}
	else
	{
		exit(0);
	}

	/*
		NL
	*/
	if (get_next_line(header->fd, &s) == 1 && s[0] != 0)
	{
		free(s);
		exit(0);
	}
	printf("%s\n", header->prog_name);
	printf("%s\n", header->comment);
	/*
		first instruct
	*/
	get_next_line(header->fd, &header->first);
}