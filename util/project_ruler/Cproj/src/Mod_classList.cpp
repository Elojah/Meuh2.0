#include "Mod_classList.h"
#include <dirent.h>
#include <fstream>

Mod_classList::Mod_classList(void) :
	WinCurse_menu()
{
	;
}

Mod_classList::Mod_classList(int h, int w, int y, int x) :
	WinCurse_menu(h, w, y, x)
{
	;
}

Mod_classList::~Mod_classList(void)
{
	;
}

void	Mod_classList::init(std::string s)
{
	DIR				*dir;
	struct dirent	*ent;
	std::string		value;
	int				found;

	_path = s;
	s += "/src";
	if ((dir = opendir(s.c_str())) == NULL)
		return ;
	while ((ent = readdir(dir)) != NULL)
	{
		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "cpp") == 0)
			_srcs.push_back(value.substr(0, found));
	}
	closedir(dir);

	setValues(_srcs, "Classes/Interfaces");
	value = choosen_value();
	_showAttributes(value);
}

void	Mod_classList::_showAttributes(std::string s)
{
	Strings			attr;
	std::string		line;
	line = _path + "/src/" + s + ".cpp";
	std::ifstream	ifs(line.c_str());
	std::size_t		found;

	if (!ifs)
		return ;
	while (std::getline(ifs, line))
	{
		if ((found = line.find(s)) != std::string::npos && line [0] != '#')
			attr.push_back(line.substr(found + s.size() + 2));
	}
	attr.push_back("Return");
	setValues(attr, s);
	line = choosen_value();
	if (line.compare("Return") == 0)
		this->init(_path);
}
