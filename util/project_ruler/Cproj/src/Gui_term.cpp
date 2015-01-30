#include "Gui_term.h"
#include <ncurses.h>
#include <signal.h>
# include "WinCurse_menu.h"
# include "WinCurse_proj.h"

Gui_term::Gui_term(void)
{
	;
}

Gui_term::~Gui_term(void)
{
	endwin();
}

void	Gui_term::init(void)
{
	initscr();
	clear();
	noecho();
	cbreak();
	raw();
	cbreak();
	keypad(stdscr, TRUE);
}

void	Gui_term::start(void)
{
	std::string	s;

	_startMenu = new WinCurse_menu("./cfg/.proj");
	s = _startMenu->choosen_value();
	delete _startMenu;
	if (s.empty())
		return ;
	_cProj = new WinCurse_proj(s);
}
