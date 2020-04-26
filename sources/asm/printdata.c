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

void tohex(int fd, int nb, int len)
{
	unsigned char	NUM[4];
	int				tmp;
	int				i;

	i = 1;
	tmp = nb;
	while (len - i != -1)
	{
		NUM[len - i] = tmp % 256;
		tmp = (tmp - NUM[len - i]) / 256;
		++i;
	}
	write(fd, NUM, len);
}

void printdata(list_t *list)
{
   	unsigned char	BUF[3000];
	int				fd;
	int				bufpt;

	printf("name is  %s %s\n", list->name, list->comment);
	ft_putstr("Writing output program to .cor\n");
	fd = open("output.cor", O_CREAT | O_RDWR, 0644);
	tohex(fd, COREWAR_EXEC_MAGIC, 4);
	write(fd, list->name, PROG_NAME_LENGTH);
	write(fd, list->comment, COMMENT_LENGTH);
	list = list->next;
	while (list)
	{
		if (!(list->ins == 0 || list->ins == 8 || list->ins == 11 || list->ins == 14))
			write(fd, list->code, 1);
		list = list->next;
	}
	close(fd);
}