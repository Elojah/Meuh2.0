#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 17:24:53 by erobert           #+#    #+#              #
#    Updated: 2015/01/20 19:25:15 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
FILES = ft_error.c ft_get_tab.c ft_get_map.c ft_max_height.c \
		ft_translate_vect.c	ft_rotate_vect.c ft_projection_vect.c \
		ft_matrix_vect.c ft_rotxy_mat.c ft_rotyz_mat.c \
		ft_color_deg.c ft_put_pixel_to_image.c \
		ft_draw_line.c ft_draw_map.c \
		main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ srcs/fdf.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
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
