#ifndef WINCURSE_PROJ_H
# define WINCURSE_PROJ_H

# include "WinCurse.h"
# include <string>
# include <vector>
class ModuleFactory;
class IWinCurse_mod;

class WinCurse_proj : public WinCurse
{
public:
	WinCurse_proj(std::string);
	~WinCurse_proj(void);
protected:
private:
	WinCurse_proj(void);
	std::string								_path;
	ModuleFactory							*_fMods;
	std::vector<IWinCurse_mod *>			_mods;

	void	_initMods(std::string);
	void	_launchMods(void);
};

#endif
