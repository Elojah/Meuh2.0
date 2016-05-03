#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/27 13:33:19 by erobert           #+#    #+#              #
#    Updated: 2014/05/14 15:15:07 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = client
FILES = ft_print_result.c ft_getfile.c ft_putfile.c ft_pwd.c ft_cd.c ft_ls.c \
		ft_client_loop.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ srcs/client.h~
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
