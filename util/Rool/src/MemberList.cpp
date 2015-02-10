#include "MemberList.hpp"
#include "MemberTemplate.hpp"
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
		if (line.find("class " + _name) != std::string::npos
			&& std::getline(ifs, line) && line.compare("{") == 0)
		{
			while (std::getline(ifs, line) && line.compare("};") != 0)
			{
				if (line.compare("public:") == 0) {
					access = "|  ";
				} else if (line.compare("protected:") == 0) {
					access = "/  ";
				} else if (line.compare("private:") == 0) {
					access = "-  ";
				} else {
					addItem(access + line, static_cast<Callback>(&MemberList::errorCallback));
				}
				while (ifs.peek() == '\t' || ifs.peek() == ' ')
					ifs.ignore();
			}
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
	memberName = readUser();
	notifyUser(tpl.create(memberName));
}
