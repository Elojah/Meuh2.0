# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 16:44:06 by leeios            #+#    #+#              #
#    Updated: 2016/08/28 19:28:14 by hdezier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#RULES
all : dirinternal
	make all -C EstimatePrice
	make all -C LinearRegression
	make all -C DrawData

clean :
	make clean -C EstimatePrice
	make clean -C LinearRegression
	make clean -C DrawData

fclean :
	make fclean -C EstimatePrice
	make fclean -C LinearRegression
	make fclean -C DrawData

re : fclean all

dirinternal:
	mkdir -p internal

