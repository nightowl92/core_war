# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:33:13 by vlaroque          #+#    #+#              #
#    Updated: 2020/01/23 20:41:51 by vlaroque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL

NAME1 = asm
NAME2 = corewar
CC = gcc
CFLAGS = -Wextra -Werror -Wall

# SOURCES

SRC_ASM = 
SRC_VM = main.c debug.c battle.c
SRC_COMMON = 

# PATH

SRC_PATH = sources
OBJ_PATH = obj
INC_PATH = includes

ASM_PATH = asm
VM_PATH = vm
COMMON_PATH = commons

# ASSIGNATION

ASM_SRC_FILES = $(addprefix $(ASM_PATH)/,$(SRC_ASM))
ASM_SRC_FILES += $(addprefix $(COMMON_PATH)/,$(SRC_COMMON))
VM_SRC_FILES = $(addprefix $(VM_PATH)/,$(SRC_VM))
VM_SRC_FILES += $(addprefix $(COMMON_PATH)/,$(SRC_COMMON))

ASM_OBJ = $(addprefix $(OBJ_PATH)/,$(ASM_SRC_FILES:.c=.o))
VM_OBJ = $(addprefix $(OBJ_PATH)/,$(VM_SRC_FILES:.c=.o))

EPENDS = $(ASM_OBJ:%.o=%.d) 
DEPENDS += $(VM_OBJ:%.o=%.d) 

.PHONY: all
all : $(NAME1) $(NAME2)

$(NAME1) : $(ASM_OBJ)
	@echo "\tLinking $@'s files"
	@$(CC) $(ASM_OBJ) -o $@ $(CFLAGS)
	@echo "\t\tDone !"

$(NAME2) : $(VM_OBJ)
	@echo "\tLinking $@'s files"
	@$(CC) $(VM_OBJ) -o $@ $(CFLAGS)
	@echo "\t\tDone !"

-include $(DEPENDS)
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@echo "\tCompiling $@"
	@$(CC) $(CFLAGS) -I$(INC_PATH) -MMD -c $< -o $@

.PHONY: clean
clean :
	@echo "\tCleaning..."
	@rm -Rf $(ASM_OBJ) $(VM_OBJ)
	@rm -Rf $(DEPENDS)
	@echo "\t\tDone !"

.PHONY: fclean
fclean : clean
	@rm -Rf $(NAME1) $(NAME2)

.PHONY: re
re :
	@$(MAKE) fclean
	@$(MAKE)
