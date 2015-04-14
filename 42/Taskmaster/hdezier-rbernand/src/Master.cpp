#include "Master.hpp"
#include <iostream>
#include <fstream>
#include <json/json.h>

Master::Master(void) {
	_ui.init();
	_ui.setTitle("Master window");
}

bool			Master::readConfig(std::string const &filename) {
	Json::Value		root;
	Json::Value		programs;
	std::ifstream	configDoc(filename.c_str(), std::ifstream::binary);
	int				i(0);

	try {
		configDoc >> root;
	} catch (std::exception &e) {
		configDoc.close();
		_ui.notifyUser("Config file is not valid.");
		return (false);
	}
	configDoc.close();
	programs = root["programs"];
	_nProgs = programs.size();
	_progs = new Programs[_nProgs]();
	for (Json::ValueIterator ijson = programs.begin(); ijson != programs.end() && i < _nProgs; ++ijson) {
		_progs[i++].setParams(*ijson);
	}
	return (true);
}


Master::Master(Master const &src) {
	if (this != &src)
		*this = src;
}

Master::~Master(void) {
	delete [] _progs;
}

void			Master::loop(void) {
	std::ofstream ofs("util/log.txt");
	for (int i = 0; i < _nProgs; ++i) {
		ofs << "Prog " << i << std::endl << _progs[i] << std::endl;
	}
	ofs.close();
	_ui.notifyUser("TEST");
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
