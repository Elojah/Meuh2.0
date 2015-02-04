#include "Mod_memberList.h"
#include "Mod_classList.h"
#include "FileTemplate.h"
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
	Strings			srcs;
	std::string		value;
	int				found;
	FileTemplate	ftmpl;

	_path = s;
	s += "/include";
	srcs.push_back("New");
	if ((dir = opendir(s.c_str())) == NULL)
		return ;
	while ((ent = readdir(dir)) != NULL)
	{
		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "hpp") == 0
			&& !value.substr(0, found).empty())
			srcs.push_back(value.substr(0, found));
	}
	closedir(dir);

	setValues(srcs, "Classes/Interfaces");
	value = choosen_value();
	if (value.compare("New") == 0)
		ftmpl.createFile(readUser(), _path);
	else if (value.compare("Return") == 0)
		return ;
	else
		_selectedClass(value);
	this->init(_path);
}

void	Mod_classList::_selectedClass(std::string &s)
{
	Mod_memberList	members(_size.h, _size.w / 2, _size.y, _size.x + _size.w / 2);

	members.init(_path, s);
}
