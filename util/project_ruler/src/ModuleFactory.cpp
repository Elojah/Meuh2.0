#include "ModuleFactory.h"
#include "IWinCurse_mod.h"
#include "Mod_classList.h"
#include <utility>

ModuleFactory::ModuleFactory(void)
{
	/*Add modules here*/
	/*
	**EXAMPLE
	_map.insert(std::pair<std::string, makeMod>(
		"name",
		accessFunction
	));
	*/
	_map.insert(std::pair<std::string, makeMod>(
		"classList",
		_makeClassList
	));
	_mapSize.insert(std::pair<std::string, makeModSize>(
		"classList",
		_makeClassListSize
	));
}

ModuleFactory::~ModuleFactory(void)
{
	;
}

IWinCurse_mod		*ModuleFactory::create(std::string s)
{
	if (_map.find(s) != _map.end())
		return (_map[s]());
	return (NULL);
}

IWinCurse_mod		*ModuleFactory::create(std::string s, int size[4])
{
	if (_mapSize.find(s) != _mapSize.end())
		return (_mapSize[s](size));
	return (NULL);
}

IWinCurse_mod		*ModuleFactory::_makeClassList(void)
{
	return (new Mod_classList());
}

IWinCurse_mod		*ModuleFactory::_makeClassListSize(int size[4])
{
	return (new Mod_classList(size[0], size[1], size[2], size[3]));
}
