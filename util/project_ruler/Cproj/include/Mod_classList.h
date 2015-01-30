#ifndef MOD_CLASSLIST_H
# define MOD_CLASSLIST_H

# include "IWinCurse_mod.h"
# include "WinCurse_menu.h"
# include <string>

class Mod_classList : public IWinCurse_mod, public WinCurse_menu
{
public:
	Mod_classList(void);
	Mod_classList(int h, int w, int y, int x);
	~Mod_classList(void);
	void	init(std::string);
protected:
private:
	Strings			_srcs;
};

#endif

