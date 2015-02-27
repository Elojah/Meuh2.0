#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 17:24:53 by erobert           #+#    #+#              #
#    Updated: 2015/02/25 13:33:24 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
FILES = ft_mode.c ft_objnew.c ft_objcmp.c ft_lstdir.c ft_lstrev.c \
		ft_lstsort.c ft_spaces.c ft_sixmonth.c ft_checkarg.c ft_totalline.c \
		ft_printobj.c ft_printfile.c ft_printdir.c ft_ls_error.c \
		ft_no_roption.c ft_roption.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ srcs/ft_ls.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./libft/ -lft -lcurses -ltermcap

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
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
