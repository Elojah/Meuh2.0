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
	IWinCurse_mod		*create(std::string const&);
	IWinCurse_mod		*create(std::string const&, int[4]);
protected:
private:
	typedef		IWinCurse_mod		*(*makeMod)(void);
	typedef		IWinCurse_mod		*(*makeModSize)(int[4]);
	static std::map<std::string, makeMod>			_map;
	static std::map<std::string, makeModSize>		_mapSize;
	static std::map<std::string, IWinCurse_mod*(*)(void)>		_create_map(void);
	static std::map<std::string, IWinCurse_mod*(*)(int[4])>	_create_mapSize(void);
	static IWinCurse_mod		*_makeClassList(void);
	static IWinCurse_mod		*_makeClassListSize(int[4]);
};

#endif

