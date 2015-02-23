#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 17:24:53 by erobert           #+#    #+#              #
#    Updated: 2015/02/23 12:56:07 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_minishell1
FILES = ft_tty.c ft_outchar.c ft_mode.c \
		ft_cpyenv.c ft_env.c ft_print_env.c ft_putprompt.c \
		ft_gotpipe.c ft_pipe.c \
		ft_gotredirection.c ft_redirection.c \
		ft_cd.c ft_getcmd.c ft_exec.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ srcs/ft_minishell1.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./libft/ -lft -lcurses -ltermcap

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: $(NAME)

$(NAME): objs_dir $(OBJS)
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
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
