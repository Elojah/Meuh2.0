#include "Master.hpp"
#include <iostream>
#include <fstream>

static void		exec(void) {
	Master		m;

	m.readConfig("./config/programs.conf");
	m.loop();
}

int			main(void) {

	initscr();
	clear();
	noecho();
	cbreak();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);

	exec();

	endwin();
	return (0);
}
