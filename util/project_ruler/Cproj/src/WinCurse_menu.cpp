#include "WinCurse_menu.h"
#include <iostream>
#include <fstream>

WinCurse_menu::WinCurse_menu(void) :
	WinCurse()
{
	;
}

WinCurse_menu::WinCurse_menu(int h, int w, int y, int x) :
	WinCurse(h, w, y, x)
{
	;
}

WinCurse_menu::WinCurse_menu(std::string const s) :
	WinCurse()
{
	std::ifstream	ifs(s.c_str());
	std::string		line;

	_m.title = s;
	while (std::getline(ifs, line))
	{
		_values[0].push_back(std::string(line));
		_values[1].push_back(_getFileName(line));
	}
	_createMenu();
}

WinCurse_menu::~WinCurse_menu(void)
{
	int		i;

	unpost_menu(_m.menu);
	free_menu(_m.menu);
	for(i = 0; i < _m.nb_item; ++i)
		free_item(_m.items[i]);
	wborder(_m.win_menu, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(_m.win_menu);
	delwin(_m.win_menu);
}

void			WinCurse_menu::setValues(Strings s, std::string title)
{
	Strings::iterator it;

	_m.title = title;
	for (it = s.begin(); it != s.end(); ++it) {
		_values[0].push_back(*it);
		_values[1].push_back("");
	}
	_createMenu();
}

std::string		WinCurse_menu::choosen_value(void)
{
	char		key;
	std::string	err;

	post_menu(_m.menu);
	wrefresh(_win);
	while((key = wgetch(_win)) != 27)
	{
		if (key == 's')
		   menu_driver(_m.menu, REQ_DOWN_ITEM);
		else if (key == 'w')
			menu_driver(_m.menu, REQ_UP_ITEM);
		else if (key == 10)
			return (std::string((char *)item_name(current_item(_m.menu))));
		wrefresh(_win);
	}
	return (err);
}

void		WinCurse_menu::_createMenu(void)
{
	int			i;

	_values[0].push_back("Exit");
	_m.nb_item = _values[0].size();
	for (i = 0; i < _m.nb_item - 1; i++)
		_m.items[i] = new_item(_values[0][i].c_str(), _values[1][i].c_str());
	_m.items[i] = new_item(_values[0][i].c_str(), "");
	_m.items[i + 1] = NULL;
	_m.menu = new_menu((ITEM **)_m.items);

	_m.win_menu = derwin(_win, _size.h - 4, _size.w - 20, 2, 10);
	set_menu_win(_m.menu, _win);
	set_menu_sub(_m.menu,_m.win_menu);
	set_menu_mark(_m.menu, "> ");
	box(_win, 0, 0);
	set_menu_format(_m.menu, _size.h, 1);
	mvwaddstr(_win, 0, (_size.w - _m.title.size()) / 2, _m.title.c_str());
	refresh();
}
