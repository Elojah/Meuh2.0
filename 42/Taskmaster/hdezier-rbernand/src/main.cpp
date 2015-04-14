#include "AWindow.hpp"
#include "UINcurses.hpp"
#include <iostream>
#include <fstream>

static void		exec(void) {
	Master		m("./config/programs.conf");

	m.loop();
}

int			main(void) {

	initscr();
	clear();
	noecho();
	cbreak();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	exec();

	endwin();
	return (0);
}
