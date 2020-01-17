/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:02:22 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/17 17:06:30 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static char		checkbit(unsigned char c, int bit)
{
	if (c & (1 << bit))
		return (1);
	else
		return (0);
}

static int		bittoint(unsigned char c)
{
	int res;
	int i;
	int nb;

	res = 0;
	i = -1;
	nb = 1;
	while (++i < 9)
	{
		if (c & (1 << i))
			res += nb;
		nb *= 2;
	}
	return (res);
}

void strbitcpy(unsigned char *src, char *dest, int bits)
{
	int i;

	i = -1;
	while (++i < bits)
		dest[i] = bittoint(src[i]);
	dest[i] = '\0';
}	

int	replaceend(char *addr, char *newend)
{
	
}

void			parserbit(char *addr, header_t *header)
{
    unsigned char	BUF[2192];
    int				fd;
	int				fdout;
	char			*outname;

    fd = open(addr, O_RDONLY);
	if (fd < 0)
		errorparser("file doesn't exist dsl", header);
	if (read(fd, BUF, PROG_NAME_LENGTH + COMMENT_LENGTH + 12) < 0)
		errorparser("file length too short bro", header);
	if (!(bittoint(BUF[0]) == 0 && bittoint(BUF[1]) == 234
	&& bittoint(BUF[2]) == 131 && bittoint(BUF[3] == 243)))
		errorparser("magic neumbeur iz no goude mec", header);
	if (!(header = malloc(sizeof(header))))
		errorparser("malloc iz no goude mec", header);
	strbitcpy(BUF+4, header->prog_name, PROG_NAME_LENGTH);
	if (!(bittoint(BUF[PROG_NAME_LENGTH + 4]) == 0 && bittoint(BUF[PROG_NAME_LENGTH + 1 + 4]) == 0
	&& bittoint(BUF[PROG_NAME_LENGTH + 2 + 4]) == 0 && bittoint(BUF[PROG_NAME_LENGTH + 3 + 4] == 0)))
		errorparser("zeros after name missing", header);
	int i = -1;
	while (++i < 128 + 2048 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4)
		printf("buf %d, %X\n", i, BUF[i]);
	strbitcpy(BUF + 4 + 4 + 4 + PROG_NAME_LENGTH, header->comment, COMMENT_LENGTH);
	printf("name %s\n", header->prog_name);
	printf("comment %s\n", header->comment);
	outname = ft_strnew(ft_strlen(addr));
	ft_strcpy(outname, addr);
	ft_strcpy(addr + ft_strlen(addr) - 2, "s");
	printf("addr is %s\n", outname);
	fdout = open(outname, O_CREAT | O_RDWR, 0644);
	write(fdout, "wesh\n" ,5);
	close(fdout);
	free(header);
	free(outname);
    close(fd);
}