#include "MemberList.hpp"
#include "MemberTemplate.hpp"
#include "ClassTemplate.hpp"
#include "SortItems.hpp"
#include <algorithm>
#include <fstream>

MemberList::MemberList(void) {
}

MemberList::MemberList(int h, int w, int y, int x) : Menu(h, w, y, x){
}

MemberList::~MemberList(void) {
}

void		MemberList::sortMenu(size_t length) {
	SortItems	sortObject0("New member", "Return");
	SortItems	sortObject1("Rename", "");

	std::sort(menuItems, menuItems + length, sortObject0);
	std::sort(&(menuItems[1]), &(menuItems[1]) + length - 2, sortObject1);
}

void	MemberList::init(const std::string &path, const std::string &name) {
	_path = path;
	_name = name;
	simpleCreate(name, "", "");
}

void	MemberList::createItems(void) {
	std::string		line;
	std::ifstream	ifs;
	std::string		access;
	std::size_t		count;

	line = _path + "/include/" + _name + ".hpp";
	access = "";
	count = 0;
	ifs.open(line.c_str());
	if (!ifs) {
		return ;
	}
	while (std::getline(ifs, line))
	{
		if (line.find("class " + _name) != std::string::npos && std::getline(ifs, line))
		{
			while (std::getline(ifs, line) && line.compare("};") != 0)
			{
				parseLine(line, count);
				if (line.empty()) {
					;
				} else if (line.compare("public:") == 0) {
					access = "|  ";
				} else if (line.compare("protected:") == 0) {
					access = "/  ";
				} else if (line.compare("private:") == 0) {
					access = "-  ";
				} else {
					addItem(access + line, static_cast<Callback>(&MemberList::errorCallback));
				}
				while (ifs.peek() == '\t' || ifs.peek() == ' ') {
					ifs.ignore();
				}
			}
			break ;
		}
	}
	ifs.close();
	addItem("New member", static_cast<Callback>(&MemberList::newMember));
	addItem("Rename", static_cast<Callback>(&MemberList::renameClass));
	addItem("Return", static_cast<Callback>(&MemberList::endMenu));
}

/*
**Define callback menus
*/
void		MemberList::newMember(ITEM *item) {
	std::string		memberName;
	MemberTemplate	tpl(_path);

	(void)item;
	tpl.initMaps();
	memberName = readUser();
	notifyUser(tpl.create(memberName));
}

void		MemberList::renameClass(ITEM *item) {
	Items::iterator	it;
	std::string		newName;
	ClassTemplate	tpl(_path);

	(void)item;
	tpl.initMaps();
	newName = readUser();
	/*Force replacement behaviour*/
	newName = "${NEW_REPLACE=" + newName + "}${OLD_REPLACE=" + _name + "}";
	notifyUser(tpl.create(newName));
	it = items.find(current_item(menu));
	it->second = static_cast<Callback>(&MemberList::endMenu);
}

void	MemberList::parseLine(std::string &line, std::size_t &count) {
	std::size_t		found;
	int				bracket;

	bracket = -1;
	if (line.empty()) {
		return ;
	}
	bracket = -1;
	while (static_cast<std::size_t>(bracket = line.find('}', bracket + 1)) != std::string::npos) {
		count--;
	}
	while (static_cast<std::size_t>(bracket = line.find('{', bracket + 1)) != std::string::npos) {
		count++;
	}
	std::replace(line.begin(), line.end(), '\t', ' ');
	while (!line.empty() && line.at(0) == ' ') {
		line.erase(0, 1);
	}
	if (count != 0 && bracket == 0) {
		line.clear();
	} else if ((found = line.find("//")) != std::string::npos
		|| (found = line.find("/*")) != std::string::npos
		|| (found = line.find("**")) != std::string::npos
		|| (found = line.find("*/")) != std::string::npos
		|| (found = line.find("{")) != std::string::npos) {
		line = line.substr(0, found);
	}
}
