#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/01/17 16:43:25 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_gkrellm
FILES = UserInfo.cpp OSInfo.cpp DateTime.cpp \
		main.cpp
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.cpp=objs/%.o)
TMPS = $(SRCS:.cpp=.cpp~) $(SRCS:.cpp=.hpp~) Makefile~ \
		IMonitorModule.hpp~ IMonitorDisplay.hpp~
CC = g++
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lncurses

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

test:
	$(CC) $(FlAG) -o $(NAME) srcs/Game.cpp srcs/Ship.cpp srcs/Player.cpp \
	srcs/AWeapon.cpp srcs/PlasmaCannon.cpp srcs/LaserGatling.cpp \
	srcs/test_unit.cpp srcs/Projectile.cpp srcs/ft_game_loop.cpp -lncurses
