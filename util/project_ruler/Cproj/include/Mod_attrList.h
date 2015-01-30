#ifndef MOD_ATTR_LIST_H
# define MOD_ATTR_LIST_H

# include "IWinCurse_mod.h"
# include "WinCurse_menu.h"
# include <string>

class Mod_attrList : public IWinCurse_mod, public WinCurse_menu
{
public:
	Mod_attrList(void);
	Mod_attrList(int h, int w, int y, int x);
	~Mod_attrList(void);
	void	init(std::string);
protected:
private:
};

#endif

