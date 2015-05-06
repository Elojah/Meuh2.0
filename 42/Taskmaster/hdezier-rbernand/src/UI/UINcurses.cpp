#include "UINcurses.hpp"
#include <iostream>

UINcurses::UINcurses(void) :
	AWindow() {
}

UINcurses::UINcurses(int h, int w, int x, int y) :
	AWindow(h, w, x, y) {
}

UINcurses::UINcurses(UINcurses const &src) {
	if (this != &src)
		*this = src;
}

UINcurses::~UINcurses(void) {
}

UINcurses		&UINcurses::operator=(UINcurses const &rhs) {
	if (this != &rhs) {
		;
	}
	return (*this);
}

void		UINcurses::serialize(std::ostream &stream) const {
	stream << "UINcurses window:";
	AWindow::serialize(stream);
}
