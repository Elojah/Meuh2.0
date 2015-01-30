#ifndef WINCURSE_MENU_H
# define WINCURSE_MENU_H

# define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

# include <menu.h>
# include <vector>
# include <string>

# include "WinCurse.h"

class WinCurse_menu : public WinCurse
{
public:
	WinCurse_menu(void);
	WinCurse_menu(const std::string);
	WinCurse_menu(int h, int w, int y, int x);
	~WinCurse_menu(void);
	std::string							choosen_value(void);
protected:
	typedef std::vector<std::string>	Strings;
	void								setValues(std::vector<std::string> s, std::string title);
private:
	typedef struct						s_menu
	{
		std::string						title;
		MENU							*menu;
		WINDOW							*win_menu;
		ITEM							*items[32];/*Nb proj max*/
		ITEM							*cur_item;
		unsigned short					nb_item;
	}									t_menu;

	t_menu								_m;
	Strings								_values[2];
	std::string							_title;

	void								_createMenu(void);
};

#endif

