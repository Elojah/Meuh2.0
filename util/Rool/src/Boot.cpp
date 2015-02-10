#include "Boot.hpp"
#include "Project.hpp"
#include "SortItems.hpp"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
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
		items[new_item(itemNames[0].back().c_str(), itemNames[1].back().c_str())]
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
