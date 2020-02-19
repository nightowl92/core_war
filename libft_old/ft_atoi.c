/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:58:38 by stherkil          #+#    #+#             */
/*   Updated: 2019/02/03 12:54:27 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *in)
{
	long long int	out;
	long long int	sign;

	if (!(*in))
		return (0);
	out = 0;
	while (*in == '\n' || *in == '\t' ||
			*in == ' ' || *in == '\r' || *in == '\v' || *in == '\f')
		in++;
	if (((sign = (*in == '-' ? -1 : 1)) == -1) || *in == '+')
		in++;
	while (ft_isdigit(*in))
	{
		out = out * 10 + *in - '0';
		in++;
	}
	return (out * sign);
}
