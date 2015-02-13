#include "X11Win.hpp"
#include <iostream>

X11Win::X11Win(void) {
	if (!(display = XOpenDisplay(NULL))) {
		std::cout << "Error: Display environment variable is wrong" << std::endl;
		return ;
	}
	_root = XDefaultRootWindow(_d);
}

X11Win::~X11Win(void) {
}

void		X11Win::init(void) {
	;
}
