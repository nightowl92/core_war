#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <stdio.h>
# include "op.h"
# include "../libft/libft.h"

void            errorparser(const char *s, header_t *header);
void			parserbit(char *addr, header_t *header);

# endif