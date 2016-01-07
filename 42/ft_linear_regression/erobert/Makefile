#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2016/01/06 16:56:51 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

TMPS = Makefile~ result
FILES = gradient-descent draw-graph
.PHONY: all clean fclean re

all:
	@make -C gradient_descent/
	@ln -sf gradient_descent/gradient-descent
	@make -C draw_graph/
	@ln -sf draw_graph/draw-graph

clean:
	@make -C gradient_descent/ clean
	@make -C draw_graph/ clean
	/bin/rm -f $(TMPS)

fclean:
	@make -C gradient_descent/ fclean
	@make -C draw_graph/ fclean
	/bin/rm -f $(FILES) $(TMPS)

re: fclean all
