#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <stdio.h>
# include "op.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

void			(*pt[17]) (t_op fct, unsigned char *BUF, int *bufptout);
void			asmparsing(header_t *header);
void			parttwo(unsigned char *BUF, int *bufptout, header_t *header);
void			errorparser(const char *s, header_t *header);
void			parserbit(char *addr, header_t *header);

# endif
