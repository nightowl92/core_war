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

static int isempty(char *s)
{
    while (*s)
    {
        if (*s > 32)
            return (0);
        s++;
    }
    return (1);
}

char *skipnl(int fd)
{
	char    *s;
	int     ret;

	while ((ret = get_next_line(fd, &s)) > 0)
	{
        if (isempty(s))
            return (s);
		free(s);
	}
    return (NULL);
}