#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/01/13 11:16:43 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = convert
FILES = main.cpp
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
