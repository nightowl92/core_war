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
	int	fd;
	char NUM[1];

	printf("name is  %s %s\n", list->name, list->comment);
	printf("outp %s\n", list->filename);
	ft_putstr("Writing output program to .cor\n");
	fd = open(list->filename, O_CREAT | O_RDWR, 0644);
	tohex(fd, COREWAR_EXEC_MAGIC, 4);
	write(fd, list->name, PROG_NAME_LENGTH);
	write(fd, list->comment, COMMENT_LENGTH);
	list = list->next;
	while (list)
	{
		NUM[0] = list->code;
		if (!(list->ins == 0 || list->ins == 8 || list->ins == 11 || list->ins == 14))
			write(fd, NUM, 1);
		printf("type is %d\n", list->type);
		list = list->next;
	}
	close(fd);
}