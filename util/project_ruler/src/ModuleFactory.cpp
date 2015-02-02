#include "ModuleFactory.h"
#include "IWinCurse_mod.h"
#include "Mod_classList.h"
#include <utility>

ModuleFactory::ModuleFactory(void)
{
	;
}

ModuleFactory::~ModuleFactory(void)
{
	;
}

IWinCurse_mod		*ModuleFactory::create(std::string const &s)
{
	if (_map.find(s) != _map.end())
		return (_map[s]());
	return (NULL);
}

IWinCurse_mod		*ModuleFactory::create(std::string const &s, int size[4])
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

/*Add modules here*/
/*
**EXAMPLE
_map.insert(std::pair<std::string, makeMod>(
	"name",
	accessFunction
));
*/
std::map<std::string, IWinCurse_mod*(*)(void)>	ModuleFactory::_create_map(void)
{
	typedef		IWinCurse_mod		*(*makeMod)(void);
	std::map<std::string, makeMod>	m;
	m.insert(std::pair<std::string, makeMod>(
		"classList",
		&(ModuleFactory::_makeClassList)
	));
	return (m);
}

std::map<std::string, IWinCurse_mod*(*)(int[4])>	ModuleFactory::_create_mapSize(void)
{
	typedef		IWinCurse_mod		*(*makeModSize)(int[4]);
	std::map<std::string, makeModSize>	m;
	m.insert(std::pair<std::string, makeModSize>(
		"classList",
		&(ModuleFactory::_makeClassListSize)
	));
	return (m);
}

std::map<std::string, IWinCurse_mod*(*)(void)>	ModuleFactory::_map = ModuleFactory::_create_map();
std::map<std::string, IWinCurse_mod*(*)(int[4])>	ModuleFactory::_mapSize = ModuleFactory::_create_mapSize();
