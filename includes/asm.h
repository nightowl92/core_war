#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <stdio.h>
# include "op.h"
# include "libft.h"

void			itobh(unsigned char *BUF, int *bufpt, long long nb);
void			asmparsing(header_t *header);
void			parttwo(unsigned char *BUF, int *bufptout, header_t *header);
void			errorparser(const char *s, header_t *header);
void			parserbit(char *addr, header_t *header);

# endif
