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
	StartMenu	_startMenu("./cfg/.proj");
	std::string	s;

	s = _startMenu.choosen_value();
	if (s.empty() || s.compare("Return") == 0)
		return ;
	else if (s.compare("New Project") == 0)
	{
		s = _startMenu.readUser();
		_createNewProject(s);
	}
	else
	{
		_cProj = new WinCurse_proj(s);
		delete _cProj;
	}
	this->start();
}

void	Gui_term::_createNewProject(std::string s)
{
	std::ifstream	ifsProj("./cfg/templates/project.template");
	std::ifstream	ifsMake("./cfg/templates/Makefile.template");
	std::ofstream	ofsMake;
	std::ofstream	ofsCfg;
	std::string		line;

	mkdir(s.c_str(), S_IRWXU);
	while (std::getline(ifsProj, line))
		mkdir((s + "/" + line).c_str(), S_IRWXU);
	ofsMake.open((s + "/Makefile").c_str());
	ofsMake << ifsMake.rdbuf();
	ofsCfg.open("./cfg/.proj", std::ios::app);
	ofsCfg << s << std::endl;
	ifsProj.close();
	ifsMake.close();
	ofsMake.close();
	ofsCfg.close();
}