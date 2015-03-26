#include "Boot.hpp"
#include "Project.hpp"
#include "SortItems.hpp"
#include "fileManip.hpp"
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

Boot::Boot(void) : Menu() {
	simpleCreate("Projects List", "New project", "Return");
}

Boot::~Boot(void) {
}

/*
**Class dependant item creation
*/
void		Boot::createItems(void)
{
	std::ifstream	ifs("./config/.proj");
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
		items[new_item(strdup(itemNames[0].back().c_str()), strdup(itemNames[1].back().c_str()))]
			= static_cast<Callback>(&Boot::openProject);
	}
	addItem("New project", static_cast<Callback>(&Boot::newProject));
	addItem("Return", static_cast<Callback>(&Boot::endMenu));
	ifs.close();
}

/*
**Callbacks
*/
void		Boot::newProject(ITEM *item) {
	std::string		projName;
	std::ofstream	ofs("./config/.proj", std::ios::app);
	std::map<std::string, std::string>	tmpMap;
	loopMap								tmpLoopMap;

	(void)item;
	projName = readUser();
	createArbo("project", projName, "");
	createNewFile("Makefile", projName + "/Makefile", tmpMap, tmpLoopMap);
	ofs << projName << std::endl;
	ofs.close();
	notifyUser("Project " + projName + " created successfully !");
}

void		Boot::openProject(ITEM *item) {
	Project		p(std::string(item_description(item)));
}
