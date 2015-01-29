#include "Mod_classList.h"
#include <dirent.h>

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

	s += "/src";
	waddstr(_win, s.c_str());

	if ((dir = opendir(s.c_str())) == NULL)
		return ;
	while ((ent = readdir(dir)) != NULL) {
		_srcs.push_back(std::string(ent->d_name));
	}
	closedir(dir);

	setValues(_srcs, "Classes");
	value = choosen_value();
}
