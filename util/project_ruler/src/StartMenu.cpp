#include "StartMenu.h"
#include <fstream>

StartMenu::StartMenu(void)
{
	;
}

StartMenu::~StartMenu(void)
{
	;
}

StartMenu::StartMenu(std::string const s) :
	WinCurse_menu()
{
	std::ifstream	ifs(s.c_str());
	std::string		line;

	_m.title = s;
	while (std::getline(ifs, line))
	{
		_values[0].push_back(std::string(line));
		_values[1].push_back(_getFileName(line));
	}
	_values[0].push_back("New Project");
	_values[1].push_back("");
	_createMenu();
}

