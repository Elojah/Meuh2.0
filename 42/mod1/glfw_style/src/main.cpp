/*
* @Author: Latias
* @Date:   2015-02-13 10:41:52
* @Last Modified by:   Latias
* @Last Modified time: 2015-02-13 10:50:54
*/

#include <vector>
#include <iostream>
#include "CocoaWin.hpp"
#include "Map.hpp"
#include "Landscape.hpp"

void	exec(char *filename) {
	CocoaWin			win(1600, 1200);
	Camera				cam;
	Map					m;
	Landscape			l(filename);

	win.init();
	l.init();
	m.addObject(&l);

	win.loop(m, cam);
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Enter a filename:\t" << std::endl;
	} else {
		exec(av[1]);
	}
	return (0);
}
