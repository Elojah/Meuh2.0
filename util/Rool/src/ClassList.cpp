#include "ClassList.hpp"
#include "Template.hpp"
#include <dirent.h>
#include <fstream>

ClassList::ClassList(void) {
}

ClassList::ClassList(int h, int w, int y, int x) : Menu(h, w, y, x){
}

ClassList::~ClassList(void) {
}

void		ClassList::init(const std::string &path, const std::string &name) {
	_path = path;
	_name = name;
	loop();
	waitUser();
}

void		ClassList::loop(void) {
	reset();
	createItems();
	setTitle(_name);
	setMenuItems();
	createMenu();
}

void		ClassList::createItems(void) {
	DIR				*dir;
	struct dirent	*ent;
	std::string		value;
	int				found;
	// FileTemplate	ftmpl;

	if ((dir = opendir((_path + "/include").c_str())) == NULL) {
		return ;
	}
	while ((ent = readdir(dir)) != NULL) {
		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "hpp") == 0
			&& !value.substr(0, found).empty()) {
			itemNames[0].push_back(value.substr(0, found));
			items[new_item(itemNames[0].back().c_str(), "")] = static_cast<Callback>(&ClassList::errorCallback);
		}
	}
	closedir(dir);

	items[new_item("New class", "")] = static_cast<Callback>(&ClassList::newClass);
	items[new_item("Return", "")] = static_cast<Callback>(&ClassList::endMenu);
}

void		ClassList::newClass(ITEM *item) {
	std::string	className;
	Template	tpl(_path);

	(void)item;
	className = readUser();
	notifyUser(tpl.create(className));
}
