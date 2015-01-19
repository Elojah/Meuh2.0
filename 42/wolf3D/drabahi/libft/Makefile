# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:23:47 by drabahi           #+#    #+#              #
#    Updated: 2014/01/11 15:26:01 by drabahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c ft_memset.c\
	ft_strlen.c ft_strdup.c \
	ft_strncpy.c ft_strchr.c \
	ft_isdigit.c ft_putchar.c\
	ft_strnew.c ft_memdel.c \
	ft_strsub.c ft_strcmp.c\
	ft_strjoin.c ft_strsplit.c\
	ft_putendl.c ft_strdel.c\
	ft_cmpmax.c ft_putnbr.c\
	ft_isnb.c \

SRCO = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

$(SRCO):
	gcc $(CFLAGS) -c $(SRCS)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all

