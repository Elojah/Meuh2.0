#include "Master.hpp"
#include <iostream>
#include <json/json.h>

const char	Master::log[15] = "./util/log.txt";

Master::Master(void) {
	_log.open(Master::log);
	if (_log.fail()) {
		_log.close();
		_log.open("/dev/null");
	}
	_log << "Init UINcurses ... " << std::endl;
	_ui.init();
	_ui.setTitle("Master window");
	_log << "Init UINcurses ... DONE" << std::endl;
}

bool			Master::readConfig(std::string const &filename) {
	Json::Value		root;
	Json::Value		processes;
	std::ifstream	configDoc(filename.c_str(), std::ifstream::binary);
	int				i(0);

	_log << "Read config file " << filename << std::endl;
	try {
		configDoc >> root;
	} catch (std::exception &e) {
		configDoc.close();
		_log << "Error reading config file !" << filename << std::endl;
		_ui.notifyUser("Config file is not valid.");
		return (false);
	}
	_log << "File syntax:\tOK" << std::endl;
	configDoc.close();
	processes = root["programs"];
	_nProcs = processes.size();
	_procs = new Process[_nProcs]();
	for (Json::ValueIterator ijson = processes.begin(); ijson != processes.end() && i < _nProcs; ++ijson) {
		_procs[i].setLog(&_log);
		_procs[i++].setParams(*ijson);
	}
	return (true);
}

Master::Master(Master const &src) {
	if (this != &src)
		*this = src;
}

Master::~Master(void) {
	delete [] _procs;
	_log.close();
}

void			Master::start(void) {
	for (int i = 0; i < _nProcs; ++i) {
		_procs[i].start();
	}
}

void			Master::loop(void) {
	for (int i = 0; i < _nProcs; ++i) {
		_procs[i].launch();
	}
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
