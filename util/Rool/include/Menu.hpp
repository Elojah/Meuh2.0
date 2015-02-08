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
	/*Item map for callback*/
	Items							items;
	/*Final Items*/
	ITEM							*menuItems[MAX_ITEMS];
	/*Name saving*/
	Strings							itemNames[2];

	void				reset(void);
	void				createMenu(void);
	void				errorCallback(ITEM *);
	void				setTitle(const std::string&);
	void				setMenuItems(void);
	void				endMenu(ITEM *);
private:
	virtual void			loop(void){}
	virtual void			sortMenu(size_t length){(void)length;}
};

#endif
