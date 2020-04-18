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
    int             type;
    struct list_s   *next;
}                   list_t;

char *skipnl(int fd);
void error(list_t *list, char *msg);
void freelist(list_t *list);
list_t *getheader(int fd, list_t *list);
void getbody(int fd, list_t *list);
list_t *newlink(list_t *list);
list_t *initlist(void);
void printdata(list_t *list);

#endif