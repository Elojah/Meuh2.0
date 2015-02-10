#ifndef MENU_H
# define MENU_H

# define MAX_ITEMS 256

# include "Window.hpp"
# include <menu.h>
# include <vector>
# include <map>

class SortItems;

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

	MENU							*menu;
	WINDOW							*winMenu;
	/*Item map for callback*/
	Items							items;
	/*Final Items*/
	ITEM							*menuItems[MAX_ITEMS];
	SortItems						*sortObject;
	/*Name saving*/
	Strings							itemNames[2];

	void				simpleCreate(const std::string&, const std::string&, const std::string&);
	void				loop(void);
	void				reset(void);
	void				createMenu(void);
	void				setMenuItems(void);

	/*
	**Usual callbacks
	*/
	void				errorCallback(ITEM *);
	void				endMenu(ITEM *);

	/*
	**Util
	*/
	void				addItem(const std::string&, Callback);
private:
	virtual void			createItems(void){}
	void					sortMenu(size_t length);
};

#endif
