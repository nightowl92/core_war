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

static void ft_putstrexit(char *str)
{
	ft_putstr(str);
	exit(0);
}

int main(int argc, char **argv)
{
    int		fd;
    list_t	*list;
	list_t	*last;

    if (argc != 2)
        ft_putstrexit("Usage: ./asm [-a] <sourcefile.s>\n -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output\n");
    if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_putstrexit("Can't read source file\n");
    list = initlist();
	list->type = 1;
	last = newlink(list);
	last->type = 2;
	last = newlink(last);
	last->type = 3;
	last = newlink(last);
	last = newlink(last);
	last->type = 0;
	last = newlink(last);
    last = getheader(fd, list);
    getbody(fd, last);
    printdata(list);
	freelist(list);
    return (0);
}