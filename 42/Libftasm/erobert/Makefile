#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/02/19 16:07:06 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libfts.a
FILES = ft_bzero.s ft_strcat.s \
		ft_isalpha.s ft_isdigit.s ft_isalnum.s ft_isascii.s ft_isprint.s \
		ft_toupper.s ft_tolower.s \
		ft_putstr.s ft_puts.s ft_strlen.s \
		ft_memset.s ft_memcpy.s ft_strdup.s \
		ft_cat.s
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.s=objs/%.o)
TMPS = $(SRCS:.s=.s~) Makefile~ incs/libfts.h~
AC = ~/.brew/Cellar/nasm/2.11.02/bin/nasm
AFLAGS = -f macho64
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L./ -lfts

.PHONY: all clean fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

objs/%.o : srcs/%.s
	$(AC) $(AFLAGS) -o $@ $^

objs_dir:
	mkdir -p objs

clean:
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean tclean
	/bin/rm -f $(NAME)

re: fclean all

tclean:
	/bin/rm -f main.o -main.c~

tmain: re
	$(CC) -g -O -c main.c

test: tmain
	$(CC) $(CFLAGS) $(LFLAGS) -o test main.o
