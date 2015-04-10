#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:31:53 by erobert           #+#    #+#              #
#    Updated: 2015/04/10 14:36:46 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

TMPS = Makefile~
FILES = audio-sfml.so gui-ncurses.so gui-sfml.so f3.so nibbler
.PHONY: all clean fclean re

all:
	@make -C audio_sfml/
	@ln -sf audio_sfml/audio-sfml.so
	@make -C gui_ncurses/
	@ln -sf gui_ncurses/gui-ncurses.so
	@make -C gui_sfml/
	@ln -sf gui_sfml/gui-sfml.so
	@make -C f3_dir/
	@ln -sf f3_dir/f3.so
	@make -C game/
	@ln -sf game/nibbler

clean:
	@make -C audio_sfml/ clean
	@make -C gui_ncurses/ clean
	@make -C gui_sfml/ clean
	@make -C f3_dir/ clean
	@make -C game/ clean
	/bin/rm -f $(TMPS)

fclean: clean
	@make -C audio_sfml/ fclean
	@make -C gui_ncurses/ fclean
	@make -C gui_sfml/ fclean
	@make -C f3_dir/ fclean
	@make -C game/ fclean
	/bin/rm -f $(FILES) $(TMPS)

re: fclean all
