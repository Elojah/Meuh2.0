#ifndef WINCURSE_PROJ_H
# define WINCURSE_PROJ_H

# include "WinCurse.h"
# include "IFactoryMod.h"
# include <string>
# include <map>
# include <vector>


class WinCurse_proj : public WinCurse
{
public:
	WinCurse_proj(std::string);
	~WinCurse_proj(void);
protected:
private:
	WinCurse_proj(void);
	std::string								_path;
	std::map<std::string, IFactoryMod *>	_modsFact;
	std::vector<IWinCurse_mod *>			_mods;

	void	_initMods(void);
	void	_createMods(std::string);
	void	_launchMods(void);
};

#endif
