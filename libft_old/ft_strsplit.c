/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 21:42:37 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/25 16:34:07 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int i;
	int out;

	i = 0;
	out = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			out++;
		while (s[i] && s[i] != c)
			s++;
	}
	return (out);
}

static int	ft_lcount(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**out;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	if (!(out = (char**)malloc(sizeof(char*) * (ft_wcount(s, c) + 1))))
		return (0);
	while (*s)
	{
		j = 0;
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(out[i] = ft_strnew((ft_lcount(s, c)))))
				return (NULL);
			while (*s && *s != c)
				out[i][j++] = *s++;
			out[i++][j] = '\0';
		}
	}
	out[i] = NULL;
	return (out);
}
