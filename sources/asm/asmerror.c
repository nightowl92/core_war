/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asmerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:07:11 by stherkil          #+#    #+#             */
/*   Updated: 2019/12/02 17:41:52 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

int		asmerror(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}