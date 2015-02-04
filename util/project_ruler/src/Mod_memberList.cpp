#include "Mod_memberList.h"
#include <fstream>

Mod_memberList::Mod_memberList(void) :
	WinCurse_menu()
{
	;
}

Mod_memberList::Mod_memberList(int h, int w, int y, int x) :
	WinCurse_menu(h, w, y, x)
{
	;
}

Mod_memberList::~Mod_memberList(void)
{
	;
}

void	Mod_memberList::init(std::string path, std::string attClass)
{
	_path = path;
	_class = attClass;
	_showClass();
}

void	Mod_memberList::_showClass(void)
{
	_showAttributes();
	_showMethods();
}


void	Mod_memberList::_showAttributes(void)
{
}

void	Mod_memberList::_showMethods(void)
{
	Strings			attr;
	std::string		line;
	line = _path + "/src/" + _class + ".cpp";
	std::ifstream	ifs(line.c_str());
	std::size_t		found;

	if (!ifs)
		return ;
	/*Parse to check Interface & remove & New*/
	while (std::getline(ifs, line))
	{
		if ((found = line.find(_class)) != std::string::npos && line [0] != '#')
			attr.push_back(line.substr(found + _class.size() + 2));
	}
	setValues(attr, _class);
	line = choosen_value();
	if (line.compare("Return") != 0)
	{
		/*TODO
		**Attributes selected
		*/
	}
}
