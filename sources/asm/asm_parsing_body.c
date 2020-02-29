/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing_body.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:01:42 by stherkil          #+#    #+#             */
/*   Updated: 2020/02/29 13:51:19 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int 	instrnametonb(char *s)
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
	else if (!ft_strncmp("ldi", s, 3))
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

int		check_labelname(char *s)
{
	int i;
	int j;
	int oknext;

	i = 0;
	while (s[i] > ' ')
	{
		oknext = 0;
		j = -1;
		while (LABEL_CHARS[++j])
			if (LABEL_CHARS[j] == s[i])
				oknext = 1;
		if (!oknext)
			return (0);
		++i;
	}
	return (i);
}

static int isinstruct(char *s, header_t *header)
{
	int i;
	int len;

	i = -1;
	len = -1;
	while (s[++len] > ' ')
		;
	if (instrnametonb(s))
		return (len);
	/*
	while (++i < 17)
		if (!ft_strncmp((op_tab[i]).instr, s, len) && (op_tab[i]).instr[0] != 0)
		{
			header->instr->instr = i + 1;
			return (len);
		}*/
	return (0);
}

int checkarg(char *s, int pt, int argnb, header_t *header)
{
	int i;

	i = 1;
	if (s[pt] == '%')
	{
		if (s[pt + 1] == LABEL_CHAR)
		{
			header->instr->islabel[argnb] = 1;
			//header->instr->labelname =  ft_strndup(s + pt + 2, (i += check_labelname(s + pt + 2)));
		}
		else
		{
			header->instr->data[argnb] = ft_atoi(s + pt + 1);
			header->instr->enc = (header->instr->enc | 1 << (7 - header->instr->ptlen * 2));
			header->tot_len += 5;
		}
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
			errorparserasm("lol", header, 0, 0);
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

	i = -1;
	while (s[++i] <= ' ')
		;
	if (header->instr->instr == 1 || header->instr->instr == 9 || header->instr->instr == 12 || header->instr->instr == 15 || header->instr->instr == 16)
		countargs(s + i, header, 1);
	else if (header->instr->instr == 2 || header->instr->instr == 3 || header->instr->instr == 13)
		countargs(s + i, header, 2);
	else
		countargs(s + i, header, 3);
}

int isvalidlabel(char *s, header_t *header)
{
	int i;
	int j;
	int found;

	i = -1;
	while (s[++i])
	{
		found = 0;
		j = -1;
		if (s[i] <= ' ')
			return (0);
		if (s[i] == LABEL_CHAR)
			return (i);
		while (LABEL_CHARS[++j])
		{
			if (LABEL_CHARS[j] == s[i])
			{
				found = 1;
				break ;
			}
		}
		if (!found)
		{
			errorparserasm("", header, 1, 0);
		}
	}
	return (0);
}

void addlabel(char *s, int len, header_t *header)
{
	labels_t			*new;

	if (!(new = malloc(sizeof(labels_t))))
		errorparser("malloc error", header);
	if (!(new->name = ft_strndup(s, len)))
		errorparser("malloc error", header);
	new->next = header->labels;
	header->labels = new;
}

static int parsecleanline(char *s, header_t *header)
{
	int i;
	int len;

	i = 0;
	while (s[i] <= ' ')
		++i;
	if (s[i] == COMMENT_CHAR)
		return (1);
	/*if ((len = isvalidlabel(s + i, header)))
	{
		addlabel(s + i, len, header);
		i += len + 1;
		if (s[i - 1] != LABEL_CHAR)
			errorparserasm("", header, 1, 0);
		while (s[i] <= ' ')
			++i;
	}*/
	if ((len = isinstruct(s + i,  header)))
		getparams(s + i + len, header);
	else
		errorparser("error label/instruc", header);
	if (!(header->instr->next = malloc(sizeof(instr_t))))
		errorparser("malloc error", header);
	header->instr->next->instr = -1;
	header->instr->next->islabel[0] = 0;
	header->instr->next->islabel[1] = 0;
	header->instr->next->islabel[2] = 0;
	header->instr = header->instr->next;
	header->instr->next = NULL;
	return (1);
}

void	asmparseinstr(header_t *header)
{
	char *s;

	s = skipnl(header);
	while (s != NULL && parsecleanline(s, header))
	{
		free(s);
		s = skipnl(header);
	}
	free(s);
}
