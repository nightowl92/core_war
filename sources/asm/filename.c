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

char	*getfilename(list_t *list, char *s)
{
	int		len;
	int		i;
	char	*out;

	i = -1;
	len = ft_strlen(s);
	printf("str and lenare %s %d %c\n", s, len, s[len - 1]);
	if (s[len - 1] != 's' && s[len - 2] != '.')
        error(list, "format error\n");
    if (!(out = ft_strnew(len + 3)))
        error(list, "malloc error\n");
    ft_strcpy(out, s);
    out[len - 1] = 'c';
    out[len] = 'o';
    out[len + 1] = 'r';
	return (out);
}