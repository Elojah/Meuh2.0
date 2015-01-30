#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 17:24:53 by erobert           #+#    #+#              #
#    Updated: 2015/01/30 19:13:29 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
FILES = ft_error.c ft_parser.c ft_put_pixel_to_image.c \
		ft_change_color.c \
		ft_draw_julia.c ft_draw_mandelbrot.c \
		ft_draw_carpet.c ft_draw_sierpinski.c\
		ft_draw_fractol.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ srcs/fract_ol.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -o3
LFLAGS = -L./libft/ -lft -L/usr/X11/lib -lXext -lX11 -lmlx -lm

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.c
	$(CC) $(CFLAGS) -Iinc -I./libft -o $@ -c $^

objs_dir:
	mkdir -p objs

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
