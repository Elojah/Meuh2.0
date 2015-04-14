#include "Master.hpp"
#include <json/json.h>
#include <iostream>
#include <fstream>

Master::Master(std::string const &filename) {
	Json::Value		root;
	std::ifstream	config_doc(filename.c_str(), std::ifstream::binary);

	_ui.init();
	_ui.setTitle("Master window");
	try {
		config_doc >> root;
	} catch (std::exception &e) {
		_ui.notifyUser("Config file is not valid.");
		return ;
	}
	// std::ifstream		ifs(filename);
	// std::string			line;

	// if (ifs.fail()) {
	// 	return ;
	// }
	// while (std::getline(ifs, line)) {
	// 	std::cout << ":\t" << line << std::endl;
	// }
	// ifs.close();
}

Master::Master(Master const &src) {
	if (this != &src)
		*this = src;
}

Master::~Master(void) {
}

void			Master::loop(void) {
	// _ui.readUser();
	_ui.notifyUser("Test");
}

Master		&Master::operator=(Master const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& stream, Master const &s) {
	(void)s;
	stream << "I am master" << std::endl;
	return (stream);
}
