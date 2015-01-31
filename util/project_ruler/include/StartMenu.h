#ifndef STARTMENU_H
# define STARTMENU_H

# include "WinCurse_menu.h"

class StartMenu : public WinCurse_menu
{
public:
	StartMenu(void);
	StartMenu(std::string const);
	~StartMenu(void);
protected:
private:
};

#endif

