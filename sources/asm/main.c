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

void ft_putstrexit(char *str, char *str2, int isexit)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putstr(str2);
	ft_putchar('\n');
	if (isexit)
		exit(0);
}

int main(int argc, char **argv)
{
	int		fd;
	list_t	*list;
	list_t	*last;

	if (argc < 2)
		ft_putstrexit("Usage: ./asm [-a] <sourcefile.s>\t", " -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output", 1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_putstrexit("Can't read source file ", argv[1], 0);
	list = initlist();
	list->filename = getfilename(list, argv[1]);
	last = getheader(fd, list);
	if (!last->type && !(last = getbody(fd, last)))
		error(list, "nothing in body\n");
	while ((last = getbody(fd, last)))
		;
	printdata(list);
	freelist(list);
	return (0);
}
