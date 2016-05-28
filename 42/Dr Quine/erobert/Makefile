#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/28 16:25:52 by erobert           #+#    #+#              #
#    Updated: 2016/05/28 19:39:29 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Colleen Grace Sully
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

Colleen: Colleen.c
	$(CC) $(FLAGS) -o $@ $^

Grace: Grace.c
	$(CC) $(FLAGS) -o $@ $^

Sully: Sully.c
	$(CC) $(FLAGS) -o $@ $^

Diff:
	clang -Wall -Wextra -Werror -o Colleen Colleen.c; ./Colleen > tmp_Colleen ; diff tmp_Colleen Colleen.c
	clang -Wall -Wextra -Werror -o Grace Grace.c; ./Grace ; diff Grace.c Grace_kid.c
	clang -Wall -Wextra -Werror Sully.c -o Sully ; ./Sully

clean:
	rm -rf Sully_*.c
	rm -rf Sully_*
	rm -rf Grace_kid.c

fclean: clean
	rm -rf $(NAME)

re: fclean all
