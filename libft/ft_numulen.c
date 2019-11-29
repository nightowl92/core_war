/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:31:57 by stherkil          #+#    #+#             */
/*   Updated: 2019/09/14 19:09:54 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int		ft_numulen(unsigned long long int nb, int base)
{
	int i;

	i = 1;
	while ((nb /= base))
		++i;
	return (i);
}
