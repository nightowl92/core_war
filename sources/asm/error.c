/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:02:22 by stherkil          #+#    #+#             */
/*   Updated: 2020/02/29 15:51:01 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void freeline(char **s)
{
	free(*s);
	*s = NULL;
}

void freelist(list_t *list)
{
	list_t  *tmp;

	while (list->next != NULL)
	{
		tmp = list;
		list = list->next;
		tmp = NULL;
		free(tmp);
	}
	free(list);
}

void error(list_t *list, char *msg)
{
	ft_putstr(msg);
	freelist(list);
	exit(0);
}
