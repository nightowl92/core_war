# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:33:13 by vlaroque          #+#    #+#              #
#    Updated: 2020/04/26 12:03:56 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL

NAME1 = asm
NAME2 = corewar
CC = clang
CFLAGS = # -Wextra -Werror -Wall -Wno-missing-field-initializers

# SOURCES

SRC_ASM = error.c  getbody.c  getheader.c  list.c  main.c  printdata.c  skipnl.c
SRC_VM = main.c debug.c battle.c champ_load.c init_corewar.c process_new.c operation_reading.c
SRC_COMMON = op.c

# PATH

SRC_PATH = sources
OBJ_PATH = obj
INC_PATH = "includes"
INC_LIBFT = "-Ilibft/includes"

ASM_PATH = asm
VM_PATH = vm
COMMON_PATH = common

# ASSIGNATION

ASM_SRC_FILES = $(addprefix $(ASM_PATH)/,$(SRC_ASM))
ASM_SRC_FILES += $(addprefix $(COMMON_PATH)/,$(SRC_COMMON))
VM_SRC_FILES = $(addprefix $(VM_PATH)/,$(SRC_VM))
VM_SRC_FILES += $(addprefix $(COMMON_PATH)/,$(SRC_COMMON))

ASM_OBJ = $(addprefix $(OBJ_PATH)/,$(ASM_SRC_FILES:.c=.o))
VM_OBJ = $(addprefix $(OBJ_PATH)/,$(VM_SRC_FILES:.c=.o))

EPENDS = $(ASM_OBJ:%.o=%.d) 
DEPENDS += $(VM_OBJ:%.o=%.d) 

# LIBRARIES
LIBFT = libft/libft.a

.PHONY: all
all : $(NAME1) $(NAME2)

$(NAME1) : $(ASM_OBJ) $(LIBFT)
	@echo "\tLinking $@'s files"
	@$(CC) $(ASM_OBJ) -o $@ $(CFLAGS) -lft -L libft 
	@echo "\t\tDone !"

$(NAME2) : $(VM_OBJ) $(LIBFT)
	@echo "\tLinking $@'s files"
	@$(CC) $(VM_OBJ) -o $@ $(CFLAGS) -lft -L libft 
	@echo "\t\tDone !"

$(LIBFT):
	@echo "\t\tMaking Libft !"
	@make -C libft

-include $(DEPENDS)
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@echo "\tCompiling $@"
	@$(CC) $(CFLAGS) -I$(INC_PATH) $(INC_LIBFT) -Ilibft -MMD -c $< -o $@ 

.PHONY: clean
clean :
	@echo "\tCleaning..."
	@rm -Rf $(ASM_OBJ) $(VM_OBJ)
	@rm -Rf $(DEPENDS)
	@echo "\t\tDone !"
	@make -C libft clean

.PHONY: fclean
fclean : clean
	@rm -Rf $(NAME1) $(NAME2)
	@make -C libft fclean

.PHONY: re
re :
	@$(MAKE) fclean
	@$(MAKE)
