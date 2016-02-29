#include "MLog.hpp"

MLog::MLog(const std::string &s) :
	AWindow(10, 20, 1, 1),
	_logFile(s) {
	setTitle(_logFile);
}

MLog::~MLog(void) {
	;
}

bool		MLog::initMod(void) {
	(void)_logFile;
	init();
	return (true);
}

bool		MLog::update(void) {
	return (true);
}
