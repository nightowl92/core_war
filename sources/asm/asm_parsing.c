/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:01:42 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/26 18:35:23 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static t_op		op_tab[17] =
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

static void	asmparsehead(header_t *header)
{
	char *s;
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
	printf("%s\n", header->prog_name);
	printf("%s\n", header->comment);
}

static int checkclean(char *s)
{
	int i;

	i = -1;
	while (++i < ft_strlen(s))
		if (s[i] > ' ')
			return (0);
	return (1);
}

static char *skipnl(header_t *header)
{
	char *s;
	int ret;

	while ((ret = get_next_line(header->fd, &s)))
	{
		if (s && s[0] && !checkclean(s))
			break ;
		free(s);
	}
	if (ret <= 0)
		errorparser("instruction section empty", header);
	return (s);
}

static int isinstruct(char *s, header_t *header, int len)
{
	int i;

	i = -1;
	while (++i < 17)
        if (!ft_strncmp((op_tab[i]).instr, s, len) && (op_tab[i]).instr[0] != 0)
		{
        	header->instr->instr = i + 1;
			return (1);
		}
	return (0);
}
static int islinevalid(char *s, header_t *header)
{
	int i;
	int ref;
	instr_t *first;

	i = 0;
	if (!(first = malloc(sizeof(instr_t))))
		errorparser("malloc error", header);
	first->next = header->instr;
	header->instr = first;
	while (s[i] <= ' ')
		++i;
	if (s[i] == COMMENT_CHAR)
	{
		free(s);
		return (1);
	}
	printf("%s\n", s + i);
	ref = i;
	while (ft_isalnum(s[i]))
		++i;
	if (s[i] != LABEL_CHAR && !isinstruct(s + ref,  header, i - ref))
		errorparser("error label/instruc", header);
	return (1);
}

static void	asmparseinstr(header_t *header)
{
	char *s;
	
	s = skipnl(header);
	islinevalid(s, header);
	//printf("s is %s\n", s);
}

void	asmparsing(header_t *header)
{
	unsigned char	BUF[2192];
	char *s;
	int ret;

	header->instr = NULL;
	asmparsehead(header);
	asmparseinstr(header);
	/*
		first instruct
	*/
}