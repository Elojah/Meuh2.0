# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shedelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/05 14:24:17 by shedelin          #+#    #+#              #
#    Updated: 2015/02/05 14:24:21 by shedelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

TARGET = libft_malloc.so
TARGET_HOST = libft_malloc_$(HOSTTYPE).so

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -ggdb

DIRLIB = libft/

DIRH = includes/

SRC = free.c \
	  realloc.c \
	  malloc.c \
	  show_alloc_mem.c \
	  init.c
      
OBJ = $(SRC:.c=.o)

test: all
	@gcc -L. -o a.out test_malloc/main.c -lft_malloc

all: init $(TARGET) link_hosttype

init:
	@make -s -C $(DIRLIB)
	@echo "\033[0;32m 					$(TARGET) PROJECT\033[0m"


$(TARGET): $(OBJ)
	@$(CC) $(FLAGS) -o $@ --shared $^ -I$(DIRLIB)$(DIRH) -I$(DIRH) -g -L$(DIRLIB) -lft 
	@echo "\033[1;32m Malloc lib done: OK\033[0m"


%.o: $(DIRSRC)%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I$(DIRLIB)$(DIRH) -I$(DIRH) -g 

clean:
	@rm -f $(OBJ)
	@echo "\033[4;32mDeleted:\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@rm -f $(TARGET) $(TARGET_HOST)
	@echo "\033[4;32mDeleted:\033[0;33m $(TARGET)\033[0m"

re: fclean all

link_hosttype :
	@ln -sF $(TARGET) $(TARGET_HOST)

.PHONY: all clean fclean re
