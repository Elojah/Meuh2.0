#include "ClassList.hpp"
#include "ClassTemplate.hpp"
#include "SortItems.hpp"
#include "MemberList.hpp"
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
	simpleCreate("Classes", "New class", "Return");
}

void		ClassList::createItems(void) {
	DIR				*dir;
	struct dirent	*ent;
	std::string		value;
	int				found;

	if ((dir = opendir((_path + "/include").c_str())) == NULL) {
		return ;
	}
	while ((ent = readdir(dir)) != NULL) {
		value = std::string(ent->d_name);
		found = value.find_last_of(".");
		if (value.compare(found + 1, value.size(), "hpp") == 0
			&& !value.substr(0, found).empty()) {
			addItem(value.substr(0, found), static_cast<Callback>(&ClassList::listAttributes));
		}
	}
	closedir(dir);
	addItem("New class", static_cast<Callback>(&ClassList::newClass));
	addItem("Return", static_cast<Callback>(&ClassList::endMenu));
}

/*
**Callbacks fcts
*/
void		ClassList::newClass(ITEM *item) {
	std::string		className;
	ClassTemplate	tpl(_path);

	(void)item;
	tpl.initMaps();
	className = readUser();
	notifyUser(tpl.create(className));
}

void	ClassList::listAttributes(ITEM *item) {
	std::string		className(item_name(item));
	MemberList		member(h - 1, w / 2, 2, w / 2);

	member.init(_path, className);
}
