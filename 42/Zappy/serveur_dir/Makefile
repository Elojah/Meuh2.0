#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/27 13:33:19 by erobert           #+#    #+#              #
#    Updated: 2015/06/09 15:24:46 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = serveur
FILES = ft_linelen.c ft_linecmp.c \
		ft_putmsz_fd.c ft_putsgt_fd.c ft_putbct_fd.c ft_putpnw_fd.c \
		ft_putenw_fd.c ft_putppo_fd.c ft_putplv_fd.c ft_putpin_fd.c \
		ft_celltoa.c ft_invtoa.c \
		ft_check_cmd.c ft_check_resource.c ft_trantor_scan.c \
		ft_action_move.c ft_action_object.c ft_action_special.c \
		ft_sock_close.c ft_player_read.c ft_gfxclt_read.c \
		ft_check_death.c ft_serveur_accept.c ft_serveur_loop.c \
		ft_print_result.c ft_lexer.c ft_trantor_init.c main.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
TMPS = $(SRCS:.c=.c~) Makefile~ incs/serveur.h~
CC = gcc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I./incs/ -I../libft/incs/
LFLAGS = -L../libft/ -lft

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	make -C ../libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.c
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

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
