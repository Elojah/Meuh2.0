#include "ClassList.hpp"

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
	items[new_item("Return", "")] = static_cast<Callback>(&ClassList::endMenu);
}
