/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:53:16 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/26 18:25:58 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	op_bzero(void *s, size_t n)
{
	while (n >= 16)
	{
		*((__int128 *)s) = 0;
		s += 16;
		n -= 16;
	}
	while (n >= 8)
	{
		*((long long *)s) = 0;
		s += 8;
		n -= 8;
	}
	while (n >= 4)
	{
		*((int *)s) = 0;
		s += 4;
		n -= 4;
	}
	while (n >= 2 && (n -= 2 || 1))
	{
		*((short *)s) = 0;
		s += 2;
	}
	if (n)
		*((char *)s) = 0;
}