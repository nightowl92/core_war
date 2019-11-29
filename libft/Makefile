NAME = libft.a

SRCS = ft_atoi.c ft_itoa.c\
	   ft_bzero.c \
	   ft_strdel.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c \
	   ft_putchar.c ft_putstr.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strdup.c ft_strncpy.c \
	   ft_strnequ.c ft_strequ.c \
	   ft_strcat.c ft_strcpy.c \
	   ft_strncat.c ft_strlcat.c\
	   ft_strtrim.c ft_strjoin.c \
	   ft_strsub.c \
	   ft_strmap.c ft_strmapi.c\
	   ft_strlen.c \
	   ft_strnlen.c \
	   ft_isdigit.c \
	   ft_intlen.c ft_isupper.c ft_isalnum.c ft_islower.c \
	   ft_isascii.c ft_isupper.c ft_isalpha.c \
	   ft_memset.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putnbrl.c \
	   ft_puthex.c \
	   ft_puthexl.c \
	   ft_puthexu.c \
	   ft_puthexul.c \
	   ft_putoct.c \
	   ft_putoctl.c \
	   ft_strnlen.c \
	   ft_strsplit.c \
	   ft_putchar_fd.c \
	   ft_putnchar.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_strstr.c ft_strnstr.c\
	   ft_tolower.c ft_toupper.c \
	   ft_isprint.c \
	   ft_strchr.c ft_strcmp.c ft_strncmp.c ft_strncmp.c\
	   ft_strrchr.c \
	   ft_strnew.c \
	   ft_lstnew.c ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_numlen.c \
	   ft_min.c  \
	   ft_max.c  \
	   ft_abs.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all		: $(NAME)

$(NAME)	: $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re : fclean all
