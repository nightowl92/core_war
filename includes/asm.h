#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <stdio.h>
# include "op.h"
# include "libft.h"

int		        check_labelname(char *s);
void            asmparsehead(header_t *header);
void            asmparseinstr(header_t *header);
void            manage_label(char *s, int type, header_t *header);
char            *skipnl(header_t *header);
void	        errorparserasm(const char *s, header_t *header, int errtyp);
void			itobh(unsigned char *BUF, int *bufpt, long long nb);
void			asmparsing(header_t *header);
void			parttwo(unsigned char *BUF, int *bufptout, header_t *header);
void			errorparser(const char *s, header_t *header);
void			parserbit(char *addr, header_t *header);

# endif
