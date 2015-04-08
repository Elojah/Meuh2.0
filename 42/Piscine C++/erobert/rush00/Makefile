#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/01/11 18:35:40 by rbobillo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro

FILES = Projectile.cpp \
		AWeapon.cpp \
		ft_game_loop.cpp \
		PlasmaCannon.cpp \
		LaserGatling.cpp \
		Ship.cpp \
		Game.cpp \
		Player.cpp \
		main.cpp

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(SRCS:srcs/%.cpp=objs/%.o)
TMPS = $(SRCS:.cpp=.cpp~) $(SRCS:.cpp=.hpp~) Makefile~ \
		ISpaceObject.hpp~ ft_retro.h~
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
