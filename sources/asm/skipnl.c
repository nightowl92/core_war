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

int     gethex(int code, int pos)
{
	if (pos == 0)
		code /= 64;
	else if (pos == 1)
		code /= 16;
	else
		code /= 4;
	return (code);
}

int		dohex(int code, int pos, int typ)
{
	if (pos == 0)
		typ *= 64;
	else if (pos == 1)
		typ *= 16;
	else
        typ *= 4;
	return (code + typ);
}

static int isempty(char *s)
{
    while (*s)
    {
        if (*s == COMMENT_CHAR)
            break ;
        if (*s > 32)
            return (0);
        s++;
    }
    return (1);
}

int skipsp(char *s, list_t *list)
{
    int i;

    i = -1;
    while (!(s[++i] > 32))
        list->y += i;
    return (i);
}

char *skipnl(int fd, list_t *list)
{
	char    *s;
	int     ret;
	int		flag;

	flag = 0;
	while ((ret = get_next_line(fd, &s)) > 0)
	{
		flag = 1;
		printf("ret is %d\n", ret);
        ++list->x;
        if (!isempty(s))
            return (s);
		free(s);
	}
	if (list->type == 0 && !flag)
		error(list, "File is empty\n");
	printf("ret is %d\n", ret);
    return (NULL);
}