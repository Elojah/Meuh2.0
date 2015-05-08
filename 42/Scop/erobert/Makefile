#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 17:24:53 by erobert           #+#    #+#              #
#    Updated: 2015/05/08 18:43:11 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = scop
FILES = ft_load_obj.c ft_load_shader.c \
		ft_addsub_vect.c ft_cross_product.c \
		ft_projection_matrix.c ft_lookat.c \
		ft_key_hook.c ft_loop_hook.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ incs/scop.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -o3
IFLAGS = -I./incs/ -I./libft/incs/ -I./minilibx_macos/
LFLAGS = -framework OpenGL -framework Cocoa \
		-L./libft/ -lft -L./minilibx_macos/ -lmlx

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

objs_dir:
	mkdir -p objs

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	make -C libft/ fclean
	make -C minilibx_macos/ clean
	/bin/rm -f $(NAME)

re: fclean all
