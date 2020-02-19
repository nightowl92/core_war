/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 22:21:12 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/25 16:32:18 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;

	if (!s)
		return (NULL);
	while (*s == '\n' || *s == '\t' || *s == ' ')
		s++;
	len = ft_strlen(s) - 1;
	if (*s)
		while (s[len] == '\n' || s[len] == '\t' || s[len] == ' ')
			len--;
	return (ft_strsub(s, 0, len + 1));
}
