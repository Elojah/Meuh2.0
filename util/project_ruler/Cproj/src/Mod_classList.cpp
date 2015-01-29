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
	int				found;

	s += "/include";
	if ((dir = opendir(s.c_str())) == NULL)
		return ;
	while ((ent = readdir(dir)) != NULL) {
		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "h") == 0)
			_srcs.push_back(value.substr(0, found));
	}
	closedir(dir);

	setValues(_srcs, "Classes/Interfaces");
	value = choosen_value();
}
