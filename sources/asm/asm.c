/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:02:22 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/21 15:47:54 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}
};

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
	int				bufpt;

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
	BUF[bufpt] = 1;
	bufpt += 1;
	write(fd, BUF, bufpt);
	printf("is %s\n", (op_tab[0]).instr);
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
