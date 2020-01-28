/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:48:49 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/16 15:22:40 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ddst;
	const char	*ssrc;

	ddst = dst;
	ssrc = src;
	while (n)
	{
		*ddst = *ssrc;
		ssrc++;
		ddst++;
		n--;
	}
	return (dst);
}
