#ifndef MODULEFACTORY_H
# define MODULEFACTORY_H

# include <map>
# include <string>
class IWinCurse_mod;

class ModuleFactory
{
public:
	ModuleFactory(void);
	~ModuleFactory(void);
	IWinCurse_mod		*create(std::string);
	IWinCurse_mod		*create(std::string s, int size[4]);
protected:
private:
	typedef		IWinCurse_mod		*(*makeMod)(void);
	typedef		IWinCurse_mod		*(*makeModSize)(int[4]);
	std::map<std::string, makeMod>			_map;
	std::map<std::string, makeModSize>		_mapSize;

	static IWinCurse_mod		*_makeClassList(void);
	static IWinCurse_mod		*_makeClassListSize(int[4]);
};

#endif

