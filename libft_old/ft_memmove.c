/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:49:30 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/19 15:16:39 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ssrc;
	char	*ddst;

	ssrc = (char*)src;
	ddst = (char*)dst;
	if (ssrc < ddst)
	{
		while (len)
		{
			ddst[len - 1] = ssrc[len - 1];
			len--;
		}
	}
	else
	{
		while (len)
		{
			*ddst = *ssrc;
			ddst++;
			ssrc++;
			len--;
		}
	}
	return (dst);
}
