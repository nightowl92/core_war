# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 13:25:30 by vlaroque          #+#    #+#              #
#    Updated: 2020/02/18 23:34:09 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

<<<<<<< HEAD
SRCS = ft_atoi.c ft_itoa.c\
	   ft_bzero.c \
	   ft_strndup.c \
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
	   ft_abs.c \
	   op_bzero.c \
	   get_next_line.c \
	   ft_strchlen.c
=======
CPPFLAGS = -I includes

CC = gcc
>>>>>>> e4f6ee8af640b74478e23c9b3d940b677adee35a

CFLAGS = -Werror -Wall -Wextra -g3

SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_nbrlen.c \
		ft_freechartab.c \
		ft_countwords.c \
		ft_power.c \
		ft_sqrt.c \
		op_bzero.c\
		get_next_line.c

OBJ = $(SRC:.c=.o)

INCLUDES = includes/

all : $(NAME)

$(NAME): $(OBJ) $(INCLUDES)libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all, clean, fclean, re
