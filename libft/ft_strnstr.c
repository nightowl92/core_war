/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:43:15 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/24 15:29:54 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_islen(size_t n, size_t i, size_t len, size_t haylen)
{
	if (n < len)
		return (0);
	if (haylen - i < len)
		return (0);
	else
		return (1);
}

char			*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	size_t j;
	size_t len;
	size_t haylen;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	len = ft_strlen(needle);
	haylen = ft_strlen(haystack);
	while (haystack[i])
	{
		if (ft_islen(n, i, len, haylen) == 0)
			return (NULL);
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (j == len - 1)
				return ((char*)(haystack + i));
			++j;
		}
		++i;
		--n;
	}
	return (NULL);
}
