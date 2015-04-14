#include "Master.hpp"
#include <iostream>
#include <fstream>

Master::Master(std::string const &filename) {
	std::ifstream		ifs(filename);
	std::string			line;

	if (ifs.fail()) {
		return ;
	}
	while (std::getline(ifs, line)) {
		;
	}
	ifs.close();
}

Master::Master(Master const &src) {
	if (this != &src)
		*this = src;
}

Master::~Master(void) {
}

void			Master::loop(void) {
	;
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
