#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/01/14 10:56:51 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = iter
FILES = iter.cpp
SRCS = $(addprefix ./, $(FILES))
OBJS = $(SRCS:./%.cpp=./%.o)
TMPS = $(SRCS:.cpp=.cpp~) $(SRCS:.cpp=.hpp~) Makefile~
CC = g++
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

./%.o : ./%.cpp
	$(CC) $(CFLAGS) -Iinc -o $@ -c $^

clean:
	/bin/rm -f $(OBJS) $(TMPS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
