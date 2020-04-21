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

static void initvalues(list_t *list)
{
	list->type = -1;
	list->x = 0;
	list->y = 0;
	list->next = NULL;
}

list_t *newlink(list_t *list)
{
	list_t *new;

	if (!(new = malloc(sizeof(list_t))))
		error(list, "malloc error\n");
	initvalues(new);
	list->next = new;
	return (new);
}

list_t	*initlist(void)
{
	list_t *list;

    if (!(list = malloc(sizeof(list_t))))
	{
		ft_putstr("malloc error\n");
		exit(0);
	}
	list->type = -1;
	initvalues(list);	
	return (list);
}