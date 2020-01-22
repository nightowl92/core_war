/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:02:22 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/22 11:46:33 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

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

static void		partone(unsigned char *BUF, int *bufptout, header_t *header)
{
	int bufpt;

	bufpt = *bufptout;
	/* find out what 0x does */
	BUF[0] = 0;
	BUF[1] = 234;
	BUF[2] = 131;
	BUF[3] = 243;
	bufpt = 4;
	/* exceptions because of length? */
	ft_memcpy(BUF + bufpt, header->prog_name, ft_strlen(header->prog_name));
	bufpt += ft_strlen(header->prog_name);
	ft_bzero(BUF + bufpt, PROG_NAME_LENGTH - ft_strlen(header->prog_name) + 7);
	bufpt += PROG_NAME_LENGTH - ft_strlen(header->prog_name) + 7;
	BUF[bufpt] = 5;
	bufpt += 1;
	ft_memcpy(BUF + bufpt, header->comment, ft_strlen(header->comment));
	bufpt += ft_strlen(header->comment);
	ft_bzero(BUF + bufpt, COMMENT_LENGTH - ft_strlen(header->comment) + 4);
	bufpt += COMMENT_LENGTH - ft_strlen(header->comment) + 4;
	*bufptout = bufpt;
}

static void		asmtofile(header_t *header, char *name1)
{
	unsigned char	BUF[2192];
	int				fd;
	char			*name2;
	int				bufpt;

	if (findlastpt(name1) == ft_strlen(name1))
		errorparser("Writing output program to .cor", header);
	if (!(name2 = ft_strndup(name1, findlastpt(name1) + 3)))
		errorparser("MALLOC ERROR", header);
	ft_strcpy(name2 + findlastpt(name1), "cor");
	fd = open(name2, O_CREAT | O_RDWR, 0644);
	partone(BUF, &bufpt, header);
	parttwo(BUF, &bufpt, header);
	write(fd, BUF, bufpt);
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
