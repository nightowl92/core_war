/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:49:37 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/17 19:17:27 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*ss;
	unsigned char		cc;

	ss = (unsigned char*)s;
	cc = (unsigned char)c;
	while (n)
	{
		if (*ss == cc)
			return (ss);
		ss++;
		n--;
	}
	return (NULL);
}
