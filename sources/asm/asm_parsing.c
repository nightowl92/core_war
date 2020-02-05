/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:01:42 by stherkil          #+#    #+#             */
/*   Updated: 2020/02/05 18:46:22 by stherkil         ###   ########.fr       */
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
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0}
};

static void getparam(header_t *header, char *s)
{
	ft_strncpy(header->prog_name, s + ft_strlen(NAME_CMD_STRING, COMMENT_CHAR) + 2, ft_strlen(s) - ft_strchlen(NAME_CMD_STRING, COMMENT_CHAR) - 3);
}

static void	asmparsehead(header_t *header)
{
	char *s;

	header->col = 1;
	s = skipnl(header);
	if (ft_strncmp(NAME_CMD_STRING, s, ft_strchlen(NAME_CMD_STRING, COMMENT_CHAR)))
		errorparserasm("", header, 3);

		free(s);
	s = skipnl(header);
	if (ft_strncmp(COMMENT_CMD_STRING, s, ft_strchlen(COMMENT_CMD_STRING, COMMENT_CHAR)))
		errorparserasm("", header, 3);
	ft_strncpy(header->comment, s + ft_strlen(COMMENT_CMD_STRING) + 2, ft_strlen(s) - ft_strlen(COMMENT_CMD_STRING) - 3);
	free(s);
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

int checkarg(char *s, int pt, int argnb, header_t *header)
{
	int i;

	i = 1;
	if (s[pt] == '%')
	{
		header->instr->data[argnb] = ft_atoi(s + pt + 1);
		header->instr->enc = (header->instr->enc | 1 << (7 - header->instr->ptlen * 2));
		header->tot_len += 5;
	}
	else if (s[pt] == 'r')
	{
		header->instr->data[argnb] = ft_atoi(s + pt + 1);
		header->instr->enc = (header->instr->enc | 1 << (6 - header->instr->ptlen * 2));
		header->tot_len += 1;
		header->tot_len += 1;
	}
	else
		errorparser("arg format NO FINE", header);
	while (ft_isalnum((s + pt)[i]))
		++i;
	header->instr->ptlen++;
	return (i);
}

void	countargs(char *s, header_t *header, int expnb)
{
	int i;
	int argnb;

	i = 0;
	argnb = 0;
	header->instr->totinstr = expnb;
	header->instr->enc = 0;
	header->instr->ptlen = 0;
	while (s[i])
	{
		if (argnb >= expnb)
			errorparserasm(op_tab[header->firstinstr->instr].instr, header, 0);
		i += checkarg(s, i, argnb, header);
		++argnb;
		while (s[i] && s[i] <= ' ')
			++i;
		if (s[i] && s[i] == SEPARATOR_CHAR)
			++i;
		while (s[i] && s[i] <= ' ')
			++i;
		if (s[i] == COMMENT_CHAR)
			break ;
	}
	if (argnb != expnb)
		errorparser("# of args NO FINE", header);
}

void	getparams(char *s, header_t *header)
{
	int i;
	int sortie;

	i = -1;
	while ((sortie = s[++i] <= ' '))
		;
	if (header->instr->instr == 1 || header->instr->instr == 9 || header->instr->instr == 12 || header->instr->instr == 15 || header->instr->instr == 16)
		countargs(s + i, header, 1);
	else if (header->instr->instr == 2 || header->instr->instr == 3 || header->instr->instr == 13)
		countargs(s + i, header, 2);
	else
		countargs(s + i, header, 3);
}

static int islinevalid(char *s, header_t *header)
{
	int i;
	int ref;

	i = 0;
	while (s[i] <= ' ')
		++i;
	if (s[i] == COMMENT_CHAR)
		return (1);
	ref = i;
	while (ft_isalnum(s[i]))
		++i;
	if (s[i] == LABEL_CHAR)
		header->instr->labelnb = (header->lastlabelnb += 1);
	else if (isinstruct(s + ref,  header, i - ref))
		getparams(s + i, header);
	else
		errorparser("error label/instruc", header);
	if (!(header->instr->next = malloc(sizeof(instr_t))))
		errorparser("malloc error", header);
	header->instr->next->instr = -1;
	header->instr = header->instr->next;
	header->instr->next = NULL;
	return (1);
}

static void	asmparseinstr(header_t *header)
{
	char *s;

	s = skipnl(header);
	while (s != NULL && islinevalid(s, header))
	{
		free(s);
		s = skipnl(header);
	}
	free(s);
}

void headerinit(header_t *header)
{
	header->instr = malloc(sizeof(instr_t));
	header->firstinstr = header->instr;
	header->instr->next = NULL;
	/*
	   header->instr = NULL;
	   */
	header->lastlabelnb = 0;
	header->tot_len = 0;
	header->col = 0;
	header->row = 0;
	header->par = 0;
}

void	asmparsing(header_t *header)
{
	//unsigned char	BUF[2192];
	char *s;
	int ret;

	s = NULL;
	ret = 0;
	headerinit(header);
	asmparsehead(header);
	asmparseinstr(header);
	instr_t *check = header->firstinstr;

	printf("name is @%s@\n", header->prog_name);
	printf("comment is @%s@\n", header->comment);

	while ((check->instr != -1))
	{
		printf("instr nb val%d data: %d %d %d\n", check->instr, check->data[0], check->data[1], check->data[2]);
		check = check->next;
	}
	/*
	   first instruct
	   */
}
