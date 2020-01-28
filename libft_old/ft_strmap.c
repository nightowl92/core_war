/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:13:41 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/25 15:30:38 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*out;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(out = ft_strnew(ft_strlen(s))))
		return (NULL);
	if (s && f)
		while (*s)
		{
			out[i] = f(*s);
			s++;
			i++;
		}
	return (out);
}
