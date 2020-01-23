/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:36:02 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/23 15:45:36 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		big_endian_int(void *ptr)
{
	int		nbr;
	int		loop;
	char	tmp;

	nbr = 0;
	loop = 0;
	tmp = ptr;
	while (loop < 4)
	{
		nbr *= 256;
		nbr += *tmp;
		tmp++;
		loop++;
	}
	return (nbr);
}
