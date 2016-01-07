#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2016/01/07 16:28:52 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

TMPS = Makefile~ result
FILES = estimate-price gradient-descent draw-graph
.PHONY: all clean fclean re

all:
	@make -C estimate_price/
	@ln -sf estimate_price/estimate-price
	@make -C gradient_descent/
	@ln -sf gradient_descent/gradient-descent
	@make -C draw_graph/
	@ln -sf draw_graph/draw-graph

clean:
	@make -C estimate_price/ clean
	@make -C gradient_descent/ clean
	@make -C draw_graph/ clean
	/bin/rm -f $(TMPS)

fclean:
	@make -C estimate_price/ fclean
	@make -C gradient_descent/ fclean
	@make -C draw_graph/ fclean
	/bin/rm -f $(FILES) $(TMPS)

re: fclean all
