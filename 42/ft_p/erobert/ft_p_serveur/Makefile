#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/27 13:33:19 by erobert           #+#    #+#              #
#    Updated: 2014/05/14 15:14:55 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = serveur
FILES = ft_getfile.c ft_putfile.c ft_pwd.c ft_cd.c ft_ls.c \
		ft_serveur_loop.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ srcs/serveur.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L../libft/ -lft

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	make -C ../libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.c
	$(CC) $(CFLAGS) -Iinc -I../libft -o $@ -c $^

objs_dir:
	mkdir -p objs

clean:
	make -C ../libft/ clean
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	make -C ../libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
