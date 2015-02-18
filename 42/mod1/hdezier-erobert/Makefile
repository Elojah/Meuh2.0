#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/02/08 14:11:45 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = mod1
FILES = Landscape.cpp UserInterface.cpp ft_parse.cpp Parser.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.cpp=objs/%.o)
TMPS = $(SRCS:.cpp=.cpp~) $(SRCS:.cpp=.hpp~) Makefile~
CC = g++
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L/usr/X11R6/lib -lX11 -lXext -lGL -lGLU
IFLAGS = -Iinclude/ -I/usr/X11R6/include

.PHONY: all clean fclean re

.SILENT: objs_dir

all: objs_dir $(NAME)

all: objs_dir $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

objs/%.o : srcs/%.cpp
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

objs_dir:
	mkdir -p objs

clean:
	/bin/rm -f $(OBJS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
