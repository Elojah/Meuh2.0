#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/27 13:33:19 by erobert           #+#    #+#              #
#    Updated: 2014/06/02 15:48:05 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = gfx client serveur
TMPS = Makefile~

.PHONY: all gfx client serveur clean fclean re

all: gfx client serveur

gfx:
	make -C gfx_dir/
	ln -sf gfx_dir/gfx gfx

client:
	make -C client_dir/
	ln -sf client_dir/client client

serveur:
	make -C serveur_dir/
	ln -sf serveur_dir/serveur serveur

clean:
	make -C gfx_dir/ clean
	make -C client_dir/ clean
	make -C serveur_dir/ clean

fclean: clean
	make -C gfx_dir/ fclean
	make -C client_dir/ fclean
	make -C serveur_dir/ fclean
	/bin/rm -f $(NAME) $(TMPS)

re: fclean all
