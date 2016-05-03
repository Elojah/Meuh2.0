#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/27 13:33:19 by erobert           #+#    #+#              #
#    Updated: 2014/05/13 14:27:11 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = client serveur
TMPS = Makefile~

.PHONY: all client serveur clean fclean re

all: client serveur

client:
	make -C ft_p_client/
	ln -sf ft_p_client/client client

serveur:
	make -C ft_p_serveur/
	ln -sf ft_p_serveur/serveur serveur

clean:
	make -C ft_p_client/ clean
	make -C ft_p_serveur/ clean

fclean: clean
	make -C ft_p_client/ fclean
	make -C ft_p_serveur/ fclean
	/bin/rm -f $(NAME) $(TMPS)

re: fclean all
