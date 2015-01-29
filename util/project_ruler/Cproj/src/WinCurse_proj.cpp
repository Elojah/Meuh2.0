#include "WinCurse_proj.h"
#include "Mod_classListFactory.h"
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
	box(_win, 0, 0);
	mvwaddstr(_win, 0, (_size.w - _path.size()) / 2, _path.c_str());
	wrefresh(_win);
	_initMods();
	_createMods("./cfg/.modules");
	_launchMods();
}

WinCurse_proj::~WinCurse_proj(void)
{
	;
}

void	WinCurse_proj::_initMods(void)
{
	/*Add modules here*/
	_modsFact.insert(std::pair<std::string, IFactoryMod *>(
		"classList",
		new Mod_classListFactory()
	));
	/*
	**EXAMPLE
	_modsFact.insert(std::pair<std::string, IFactoryMod *>(
		"name",
		new Mod_nameFactory()
	));
	*/
}

void	WinCurse_proj::_createMods(std::string s)
{
	std::ifstream	ifs(s.c_str());
	std::string		line;

	while (std::getline(ifs, line))
	{
		if (_modsFact.find(line) == _modsFact.end())
			continue ;
		_mods.push_back(_modsFact[line]->create(_size.h / 2, _size.w / 2, 1, 1));
	}
}

void	WinCurse_proj::_launchMods(void)
{
	std::vector<IWinCurse_mod *>::iterator it;

	for (it = _mods.begin(); it != _mods.end(); ++it) {
		(*it)->init(_path);
	}
}
