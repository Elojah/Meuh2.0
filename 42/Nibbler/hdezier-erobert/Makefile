#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/04/08 16:24:46 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = nibbler
FILES = Game.cpp Time.cpp main.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.cpp=objs/%.o)
INCS = $(SRCS:srcs/%.cpp=incs/%.hpp) incs/IGUINibbler.hpp
TMPS = $(SRCS:.cpp=.cpp~) $(INCS:.hpp=.hpp~) Makefile~
CC = g++
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -Iincs/
LFLAGS =

.PHONY: all clean objs_dir child fclean re

.SILENT: objs_dir child

all: objs_dir child $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.cpp
	$(CC) $(CFLAGS) -Iinc $(IFLAGS) -o $@ -c $^

objs_dir:
	mkdir -p objs

child:
	make -C e1/
	make -C f1/
	make -C f2/
	make -C f3/

clean:
	make -C e1/ clean
	make -C f1/ clean
	make -C f2/ clean
	make -C f3/ clean
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	make -C e1/ fclean
	make -C f1/ fclean
	make -C f2/ fclean
	make -C f3/ fclean
	/bin/rm -f $(NAME)

re: fclean all
