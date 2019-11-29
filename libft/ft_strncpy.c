/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:10:18 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/19 17:09:29 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	n;

	n = ft_strlen(src);
	if (n < len)
	{
		ft_memcpy(dst, src, n);
		ft_bzero(dst + n, len - n);
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
