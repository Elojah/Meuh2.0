# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/07 19:38:40 by drabahi           #+#    #+#              #
#    Updated: 2014/05/28 21:37:20 by drabahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c get_next_line.c error.c depart.c initial.c move.c tracer.c \
	color.c pos.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

# CFLAGS = -L/usr/X11/lib/ -lmlx -lXext -lX11 -L./libft/ -lft
CFLAGS = -L./libft/ -L/usr/X11R6/lib -lX11 -lXext \
		-framework OpenGL -framework AppKit -L./minilibx_macos/ -lm -lft -lmlx
INC = -Iinclude/ -I./libft -I./minilibx_macos -I/usr/X11R6/include

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) -c $(SRC) -g3
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean :
	@make clean -C libft/
	@/bin/rm -f $(OBJ)

fclean : clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re : fclean all
