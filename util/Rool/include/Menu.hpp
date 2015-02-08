#ifndef MENU_H
# define MENU_H

# define MAX_ITEMS 256

# include "Window.hpp"
# include <menu.h>
# include <vector>
# include <map>

class Menu : public Window
{
public:
	typedef std::vector<std::string>	Strings;

	Menu(void);
	Menu(int, int, int, int);
	~Menu(void);

	void			waitUser(void);

protected:
	typedef void	(Menu::*Callback)(ITEM *);
	typedef std::map<ITEM *, Callback> Items;

	std::string						title;
	MENU							*menu;
	WINDOW						*winMenu;
	/*Final Items*/
	ITEM							*menuItems[MAX_ITEMS];
	/*Item map for callback*/
	Items							items;
	/*Name saving*/
	Strings							itemNames;

	void			reset(void);
	void			errorCallback(ITEM *);
	void			setTitle(const std::string&);
	void			setMenuItems(void);
private:
	void			_createMenu(void);
	virtual void		loop(void){}
};

#endif
