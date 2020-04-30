#ifndef ASM_H
# define ASM_H

#include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "op.h"
# include "libft.h"

typedef struct		list_s
{
	char			*filename;
	char			*label;
    int				type;
	int				ins;
	int				code;
    int				x;
    int				y;
    char			name[PROG_NAME_LENGTH];
	char			comment[COMMENT_LENGTH];
    char            *line;
    struct list_s   *next;
}                   list_t;

char	*getfilename(list_t *list, char *s);
int		dohex(int code, int pos, int typ);
int		gethex(int code, int pos);
void	freeline(char **s);
int		skipsp(char *s, list_t *list);
char	*skipnl(int fd, list_t *list);
void	error(list_t *list, char *msg);
void	freelist(list_t *list);
list_t	*getheader(int fd, list_t *list);
list_t	*getbody(int fd, list_t *list);
list_t	*newlink(list_t *list);
list_t	*initlist(void);
void	printdata(list_t *list);

#endif