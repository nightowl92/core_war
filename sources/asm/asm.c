/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:02:22 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/20 14:39:54 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void	asmparsing(header_t *header)
{
	unsigned char	BUF[2192];
	char *s;
	int ret;

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
	
	printf("%s\n", header->prog_name);
	printf("%s\n", header->comment);
	/*if (read(fd, BUF, PROG_NAME_LENGTH + COMMENT_LENGTH + 12) < 0)
		errorparser("file length too short bro", header);*/
}

static int findlastpt(char *addr)
{
	int		len;
	char	*cpyaddr;

	if (!(cpyaddr = NULL))
	len = ft_strlen(addr);
	while (--len)
		if (addr[len - 1] == '.')
			break ;
	return (len);
}

static void		asmtofile(header_t *header, char *name1)
{
	unsigned char	BUF[2192];
	int				fd;
	char			*name2;

	if (findlastpt(name1) == ft_strlen(name1))
		errorparser("Writing output program to .cor", header);
	if (!(name2 = ft_strndup(name1, findlastpt(name1) + 3)))
		errorparser("MALLOC ERROR", header);
	ft_strcpy(name2 + findlastpt(name1), "cor");
	fd = open(name2, O_CREAT | O_RDWR, 0644);
	/* find out what 0x does */
	BUF[0] = 0;
	BUF[1] = 234;
	BUF[2] = 131;
	BUF[3] = 243;
	ft_strcpy(BUF + 4, (unsigned char*)(header->prog_name));
	write(fd, BUF, 4);
	//write(fd, "bonjour\n", 8);
	free(name2);
	close(fd);
}


int			main(int argc, char **argv)
{
	header_t	*header;

	header = NULL;
	header = malloc(sizeof(header_t));
	if (argc != 2)
		errorparser("Usage: ./asm [-a] <sourcefile.s>\n -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output", header);		
	if ((header->fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putstr("Can't read source file ");
		errorparser(argv[1], header);
	}
	asmparsing(header);
	close(header->fd);
	asmtofile(header, argv[1]);
	return (0);
}
