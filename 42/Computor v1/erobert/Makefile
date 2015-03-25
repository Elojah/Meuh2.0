#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/03/25 15:11:38 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = computor
FILES = Lexer.cpp Parser.cpp Polynomial.cpp main.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.cpp=objs/%.o)
TMPS = $(SRCS:.cpp=.cpp~) $(SRCS:.cpp=.hpp~) Makefile~
CC = g++
CFLAGS = -Wall -Wextra -Werror
LFLAGS = 

.PHONY: all clean fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.cpp
	$(CC) $(CFLAGS) -Iinc -o $@ -c $^

objs_dir:
	mkdir -p objs

clean:
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
