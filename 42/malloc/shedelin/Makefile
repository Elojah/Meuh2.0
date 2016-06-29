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

NAME = libft_malloc_x86_64.so

CC = /usr/local/bin/gcc

FLAGS = -Wall -Wextra -Werror -g -ggdb

DIRLIB = libft/

DIRH = includes/

SRC = free.c \
	  realloc.c \
	  malloc.c \
	  show_alloc_mem.c \
	  init.c
      
OBJ = $(SRC:.c=.o)

all: init $(NAME)

init:
	@make -s -C $(DIRLIB)
	@echo "\033[0;32m 					$(NAME) PROJECT\033[0m"


$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ --shared $^ -I$(DIRLIB)$(DIRH) -I$(DIRH) -g -L$(DIRLIB) -lft 
	@echo "\033[1;32m Malloc lib done: OK\033[0m"


%.o: $(DIRSRC)%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I$(DIRLIB)$(DIRH) -I$(DIRH) -g 

clean:
	@rm -f $(OBJ)
	@echo "\033[4;32mDeleted:\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[4;32mDeleted:\033[0;33m $(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re
