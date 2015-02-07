#include "Menu.hpp"

Menu::Menu(void) : Window(),
					menu(NULL),
					winMenu(NULL) {
	menuItems[0] = NULL;
}

Menu::Menu(int h, int w, int y, int x) : Window(h, w, y, x),
										menu(NULL),
										winMenu(NULL) {
	menuItems[0] = NULL;
}

Menu::~Menu(void) {
	int		i;

	for (i = 0; menuItems[i]; ++i) {
		free_item(menuItems[i]);
	}
	if (menu) {
		unpost_menu(menu);
		free_menu(menu);
	}
	if (winMenu) {
		wborder(winMenu, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(winMenu);
		delwin(winMenu);
	}
}

void			Menu::waitUser(void)
{
	char			key;
	Items::iterator	it;

	_createMenu();
	wrefresh(win);
	while((key = wgetch(win)) != 27)
	{
		if (key == 's') {
		   menu_driver(menu, REQ_DOWN_ITEM);
		} else if (key == 'w') {
			menu_driver(menu, REQ_UP_ITEM);
		} else if (key == 10) {
			if ((it = items.find(current_item(menu))) != items.end())
				(this->*(it->second))(current_item(menu));
			else
				errorCallback(current_item(menu));
			// return ;
		}
		wrefresh(win);
	}
}

void			Menu::errorCallback(ITEM *item) {
	notifyUser(std::string(item_name(item)) + " callback is not define");
	getch();
}

void			Menu::setTitle(std::string const &titleSet)
{
	title = std::string(titleSet);
	mvwaddstr(win, 0, (w - title.size()) / 2, title.c_str());
}

void			Menu::setItems(void)
{
	size_t		i;

	i = 0;
	for (Items::iterator it = items.begin(); it != items.end(); it++) {
		menuItems[i] = it->first;
		i++;
	}
	menuItems[i] = NULL;
}

void			Menu::_createMenu(void)
{
	menu = new_menu((ITEM **)menuItems);
	winMenu = derwin(win, h - 4, w - 4, 2, 2);
	set_menu_win(menu, win);
	set_menu_sub(menu, winMenu);
	set_menu_mark(menu, "> ");
	box(win, 0, 0);
	set_menu_format(menu, h - 4, 1);
	post_menu(menu);
	wrefresh(winMenu);
	refresh();
}
