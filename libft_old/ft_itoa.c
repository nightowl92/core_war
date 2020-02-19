/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:04:50 by stherkil          #+#    #+#             */
/*   Updated: 2019/01/25 13:23:31 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_neg(int nb)
{
	int		l;
	char	*s;

	l = ft_intlen(nb) + 1;
	if (!(s = ft_strnew(l)))
		return (NULL);
	while (l - 1)
	{
		s[l - 1] = nb % 10 + '0';
		nb /= 10;
		l--;
	}
	s[0] = '-';
	return (s);
}

char		*ft_itoa(int nb)
{
	char	*s;
	int		l;

	if (nb == -2147483648)
	{
		if (!(s = ft_strnew(11)))
			return (NULL);
		return (ft_strcpy(s, "-2147483648"));
	}
	l = ft_intlen(nb);
	if (nb < 0)
		return (itoa_neg(-nb));
	if (!(s = ft_strnew(l)))
		return (NULL);
	while (l)
	{
		s[l - 1] = nb % 10 + '0';
		nb /= 10;
		l--;
	}
	return (s);
}
