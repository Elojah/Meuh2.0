#include "Project.hpp"
#include <libgen.h>
#include <string.h>
#include <stdlib.h>

Project::Project(void) {
}

Project::Project(std::string const &path) : Menu() {
	char	*tmp;

	tmp = strdup(path.c_str());
	_path = std::string(path);
	_name = std::string(basename(tmp));
	free(tmp);
	// loop();
	// waitUser();
}

Project::~Project(void) {
}

void		Project::loop(void) {
	reset();
	createItems();
	setTitle(_name);
	setMenuItems();
}

void		Project::createItems(void) {
	;
	items[new_item("Return", "")] = static_cast<Callback>(&Project::endMenu);
}
