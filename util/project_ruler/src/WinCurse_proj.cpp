#include "WinCurse_proj.h"
#include "ModuleFactory.h"
#include "IWinCurse_mod.h"
#include <fstream>

WinCurse_proj::WinCurse_proj(void) :
	WinCurse::WinCurse()
{
	;
}

WinCurse_proj::WinCurse_proj(std::string path) :
	WinCurse::WinCurse(),
	_path(path)
{
	_fMods = new ModuleFactory();

	box(_win, 0, 0);
	mvwaddstr(_win, 0, (_size.w - _path.size()) / 2, _path.c_str());
	wrefresh(_win);

	_initMods("./cfg/.modules");
	_launchMods();
}

WinCurse_proj::~WinCurse_proj(void)
{
	delete _fMods;
}

void	WinCurse_proj::_initMods(std::string s)
{
	std::ifstream	ifs(s.c_str());
	std::string		line;
	IWinCurse_mod	*tmp;
	int				size[4] = {_size.h / 2, _size.w, 1, 1};/*HARDCODE*/

	while (std::getline(ifs, line))
	{
		if (line.at(0) != '#' && (tmp = _fMods->create(line, size)) != NULL)/*HARDCODE*/
			_mods.push_back(tmp);
	}
}

void	WinCurse_proj::_launchMods(void)
{
	std::vector<IWinCurse_mod *>::iterator it;

	for (it = _mods.begin(); it != _mods.end(); ++it) {
		(*it)->init(_path);
	}
}
