/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 13:51:22 by leeios            #+#    #+#             */
/*   Updated: 2015/08/10 13:39:49 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Boot.hpp"

void		exec(void) {
	Boot	b;
}

int			main(int ac, char **av) {

	(void)ac;
	(void)av;

	initscr();
	clear();
	noecho();
	cbreak();
	raw();
	cbreak();
	keypad(stdscr, TRUE);

	exec();

	endwin();
	return (0);
}
