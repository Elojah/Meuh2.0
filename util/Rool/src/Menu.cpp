#include "Menu.hpp"

Menu::Menu(void) : Window(),
					menu(NULL),
					winMenu(NULL);
{
	;
}

Menu::Menu(int h, int w, int y, int x) : Window(h, w, y, x),
										menu(NULL),
										winMenu(NULL);
{
	;
}

Menu::~Menu(void)
{
	int		i;

	for (i = 0; items[i]; ++i)
		free_item(items[i]);
	if (menu)
	{
		unpost_menu(menu);
		free_menu(menu);
	}
	if (winMenu)
	{
		wborder(winMenu, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(winMenu);
		delwin(winMenu);
	}
}

ITEM			*Menu::waitUser(void)
{
	char		key;

	_createMenu();
	wrefresh(win);
	while((key = wgetch(win)) != 27)
	{
		if (key == 's')
		   menu_driver(menu, REQ_DOWN_ITEM);
		else if (key == 'w')
			menu_driver(menu, REQ_UP_ITEM);
		else if (key == 10)
			return (current_item(menu));
		wrefresh(win);
	}
	return (new_item("undefined", "undefined"));
}

void			Menu::setTitle(std::string const &titleSet)
{
	title = std::string(titleSet);
}

void			Menu::setItems(ListItem const &list)
{
	unsigned int		i;

	for (i = 0; i < list.size(); i++)
	{
		if (!(items[i] = new_item(
			list.at(i).name.c_str(),
			list.at(i).descr.c_str())))
			break ;
		set_item_userptr(items[i], list.callback);
	}
	items[i] = NULL;
}

void			Menu::_createMenu(void)
{
	mvwaddstr(win, 0, (w - title.size()) / 2, title.c_str());
	menu = new_menu((ITEM **)items);
	winMenu = derwin(win, h - 4, w - 4, 2, 2);
	set_menu_win(menu, win);
	set_menu_sub(menu, winMenu);
	set_menu_mark(menu, "> ");
	box(win, 0, 0);
	set_menu_format(menu, h - 4, 1);
	post_menu(menu);
	wrefresh(winMenu);
}
