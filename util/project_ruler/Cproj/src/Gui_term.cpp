#include "Gui_term.h"
#include <ncurses.h>
#include <signal.h>

Gui_term::Gui_term(void)
{
	;
}

Gui_term::~Gui_term(void)
{
	;
}

void	Gui_term::init(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	clear();
}

void	Gui_term::loop(void)
{
	;
}
