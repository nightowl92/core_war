/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:01:50 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/17 19:07:45 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ddst;
	unsigned char		*ssrc;

	ddst = (unsigned char*)dst;
	ssrc = (unsigned char*)src;
	while (n)
	{
		*ddst = *ssrc;
		if (*ssrc == (unsigned char)c)
			return (ddst + 1);
		ssrc++;
		ddst++;
		n--;
	}
	return (NULL);
}
