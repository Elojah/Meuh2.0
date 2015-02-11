#include "MemberList.hpp"
#include "MemberTemplate.hpp"
#include <algorithm>
#include <fstream>

MemberList::MemberList(void) {
}

MemberList::MemberList(int h, int w, int y, int x) : Menu(h, w, y, x){
}

MemberList::~MemberList(void)
{
	;
}

void	MemberList::init(const std::string &path, const std::string &name) {
	_path = path;
	_name = name;
	simpleCreate(name, "New member", "Return");
}

void	MemberList::createItems(void) {
	std::string		line;
	std::ifstream	ifs;
	std::string		access;

	line = _path + "/include/" + _name + ".hpp";
	access = "";
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
				parseLine(line);
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
	box(user, 1, 1);
	memberName = readUser();
	notifyUser(tpl.create(memberName));
}

void	MemberList::parseLine(std::string &line) {
	std::size_t		found;

	if (line.empty()) {
		return ;
	}
	std::replace(line.begin(), line.end(), '\t', ' ');
	while (!line.empty() && line.at(0) == ' ') {
		line.erase(0, 1);
	}
	if ((found = line.find("//")) != std::string::npos
		|| (found = line.find("/*")) != std::string::npos
		|| (found = line.find("**")) != std::string::npos
		|| (found = line.find("*/")) != std::string::npos) {
		line = line.substr(0, found);
	}
}
