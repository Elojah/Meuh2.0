#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/12 18:06:35 by rduclos           #+#    #+#              #
#    Updated: 2014/05/25 17:04:05 by rduclos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
FLAGS = -Wall -Wextra -Werror -g3
LIB = libft/
INCLUDES = headers/

CC = gcc

DIROBJ = objs/
DIRSRC = srcs/

SRC =	main.c parse.c solve.c tetrilist.c draw.c board.c save_tetris.c \
		tools.c solve2.c

OBJ = $(SRC:%.c=$(DIROBJ)%.o)

all: init $(NAME)

init:
	@mkdir -p $(DIROBJ)
	@make -C libft/

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $(OBJ) -I $(INCLUDES) -L $(LIB) -lft -I $(LIB)
	@tput cuu1
	@echo "\033[2K\t\033[1;36m$(NAME)\t\t\033[0;32m[Ready]\033[0m"

$(DIROBJ)%.o: $(DIRSRC)%.c
	@echo "==> Compiling $<"
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INCLUDES) -I $(LIB)

clean:
	@make -C $(LIB) clean
	@rm -rf $(DIROBJ)
	@echo "[$(NAME)]--> Objects removed"

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
	@echo "[$(NAME)]--> Program removed"

re: fclean all
