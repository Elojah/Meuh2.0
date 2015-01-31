#include "Gui_term.h"
#include <ncurses.h>
#include <signal.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
# include "StartMenu.h"
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

	_startMenu = new StartMenu("./cfg/.proj");
	s = _startMenu->choosen_value();
	if (s.empty())
		return ;
	else if (s.compare("New Project") == 0)
	{
		s = _startMenu->readUser();
		_createNewProject(s);
	}
	else
		_cProj = new WinCurse_proj(s);
	delete _startMenu;
}

void	Gui_term::_createNewProject(std::string s)
{
	std::ifstream	ifs("./cfg/templates/project.template");
	std::ofstream	ofs((s + "/Makefile").c_str());
	std::string		line;

	mkdir(s.c_str(), S_IRWXU);
	while (std::getline(ifs, line))
		mkdir((s + "/" + line).c_str(), S_IRWXU);
	ifs.close();
	ifs.open("./cfg/templates/Makefile");
	ofs << ifs.rdbuf();
}
