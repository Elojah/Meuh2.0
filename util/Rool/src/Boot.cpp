#include "Boot.hpp"
#include "Project.hpp"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <algorithm>

Boot::Boot(void) : Menu() {
	loop();
	waitUser();
}

Boot::~Boot(void) {
}

bool		Boot::sortFn(const ITEM *lhs, const ITEM *rhs) {
	if (!lhs || !rhs) {
		return (false);
	}
	std::string	lstr(item_name(lhs));
	std::string	rstr(item_name(rhs));

	if (lstr.compare("Return") == 0 || rstr.compare("New project") == 0) {
		return (false);
	}
	if (lstr.compare("New project") == 0 || rstr.compare("Return") == 0) {
		return (true);
	}
	return (lstr.compare(rstr) < 0);
}

void		Boot::sortMenu(size_t length) {
	std::sort(menuItems, menuItems + length
		, Boot::sortFn);
	// size_t	i;
	// for (i = 0; i < length - 1; i++) {
	// 	notifyUser(item_name(menuItems[i]));
	// 	getch();
	// }
}

/*
**Main loop
*/
void		Boot::loop(void) {
	reset();
	createItems("./config/.proj");
	setTitle("Projects list");
	setMenuItems();
	createMenu();
}

/*
**Class dependant item creation
*/
void		Boot::createItems(const std::string &configFile)
{
	std::ifstream	ifs(configFile.c_str());
	std::string		line;
	char			*tmp;

	if (ifs.fail()) {
		std::cout << "Error: File ./config/.proj doesn't exist." << std::endl;
		return ;
	}
	while (std::getline(ifs, line)) {
		if (line.empty() || line.at(0) == '#') {
			continue ;
		}
		itemNames[1].push_back(line);
		tmp = strdup(line.c_str());
		itemNames[0].push_back(std::string(basename(tmp)));
		free(tmp);
		items[new_item(itemNames[0].back().c_str(), itemNames[1].back().c_str())]
			= static_cast<Callback>(&Boot::openProject);
	}
	items[new_item("New project", "")] = static_cast<Callback>(&Boot::newProject);
	items[new_item("Return", "")] = static_cast<Callback>(&Boot::endMenu);
	ifs.close();
}

/*
**Callbacks
*/
void		Boot::newProject(ITEM *item) {
	std::string		projName;
	std::ifstream	ifsProj("./config/templates/project.template");
	std::ifstream	ifsMake("./config/templates/Makefile.template");
	std::ofstream	ofsMake;
	std::ofstream	ofsCfg;
	std::string		line;

	(void)item;
	projName = readUser();
	if (!projName.empty()) {
		mkdir(projName.c_str(), S_IRWXU);
		while (std::getline(ifsProj, line))
			mkdir((projName + "/" + line).c_str(), S_IRWXU);
		ofsMake.open((projName + "/Makefile").c_str());
		ofsMake << ifsMake.rdbuf();
		ofsCfg.open("./config/.proj", std::ios::app);
		ofsCfg << projName << std::endl;
		notifyUser("Project " + projName + " created successfully !");
	}
	ifsProj.close();
	ifsMake.close();
	ofsMake.close();
	ofsCfg.close();
}

void		Boot::openProject(ITEM *item) {
	Project		p(std::string(item_description(item)));
}
