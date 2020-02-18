/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:56:00 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/30 15:15:42 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "corewar.h"

void		char_hexa(t_octet c)
{
	char	base[] = "0123456789abcdef";
	
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void		hex_dump(t_octet *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (i != 0 && i % 64 == 0)
			write(1, "\n", 1);
		else if (i != 0)
			write(1, " ", 1);
		char_hexa(*src);
		src++;
		i++;
	}
	write(1, "\n", 1);
}

//128 64 32 16 8 4 2 1

int			champ_dump(t_champ *champ)
{
	if (!champ)
		return (-1);
	ft_putstr("champ id =|");
	ft_putstr(ft_itoa(champ->id));
	ft_putstr("|\nNAME = |");
	ft_putstr((char *)champ->prog_name);
	ft_putstr("|\nCOMMENT = |");
	ft_putstr((char *)champ->comment);
	ft_putstr("|\nCHAMPION");
	hex_dump(champ->content, CHAMP_MAX_SIZE);
	ft_putstr("|\n");
	return (0);
}

int			show_mars(t_data *data)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
//		if (i == 1023)
//			write(1, "@", 1);
//		if (i == 684)
//			write(1, "@", 1);
		if (i != 0 && i % 64 == 0)
			write(1, "\n", 1);
		else if (i != 0)
			write(1, " ", 1);
		char_hexa(data->mars[i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
