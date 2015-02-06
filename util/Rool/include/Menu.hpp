#ifndef MENU_H
# define MENU_H

# define MAX_ITEMS 256

# include "Window.hpp"
# include <menu.h>
# include <vector>

class Menu : public Window
{
public:
	Menu(void);
	Menu(int, int, int, int);
	~Menu(void);

	typedef struct	s_item_full
	{
		std::string	name;
		std::string	descr;
		void		(*callback)(char *);
	}				t_item_full;
	typedef std::vector<std::string>	Strings;
	typedef std::vector<t_item_full>	ListItem;

	ITEM			*waitUser(void);
protected:
	std::string		title;
	MENU			*menu;
	WINDOW		*winMenu;
	ITEM			*items[MAX_ITEMS];
	void			setTitle(const std::string&);
	void			setItems(const ListItem&);
private:
	void			_createMenu(void);
};

#endif
