#include "Boot.hpp"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

Boot::Boot(void) : Menu() {
	loop();
}

Boot::~Boot(void) {
}

void		Boot::loop(void) {
	std::ifstream	ifs("./config/.proj");
	std::string		line;

	reset();
	if (ifs.fail()) {
		std::cout << "Error: File ./config/.proj doesn't exist." << std::endl;
		return ;
	}
	while (std::getline(ifs, line)) {
		if (line.empty() || line.at(0) == '#') {
			continue ;
		}
		itemNames.push_back(line);
		items[new_item(itemNames.back().c_str(), "")] = static_cast<Callback>(&Boot::errorCallback);
	}
	items[new_item("New project", "")] = static_cast<Callback>(&Boot::newProject);
	ifs.close();
	setTitle("Projects list");
	setMenuItems();
	waitUser();
}

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
