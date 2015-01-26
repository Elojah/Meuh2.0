#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 00:04:48 by drabahi           #+#    #+#              #
#    Updated: 2015/01/23 00:04:48 by drabahi          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
FILES = main.c calculus.c draw_lib.c main_loop.c calc_grid.c
SRC = $(addprefix src/, $(FILES))
OBJ = $(SRC:src/%.c=obj/%.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L./libft/ -L/usr/X11R6/lib -lX11 -lXext\
		-framework OpenGL -framework AppKit -L./minilibx_macos/ -lm -lft -lmlx
INC = -Iinclude/ -I./libft -I./minilibx_macos -I/usr/X11R6/include


all: objs_dir $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "\033[33mCompiler \033[0m"

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $^

objs_dir:
	@mkdir -p obj

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ) $(TMPS)
	@/bin/rm -rf obj
	@echo "\033[33mEffacer \033[0m"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all objs_dir clean fclean re

.SILENT: objs_dir
