#include "CocoaWin.hpp"
#include "Landscape.hpp"
#include "IObject.hpp"
#include <iostream>

int		main(int ac, char **av) {
	CocoaWin		*win;
	Landscape	*land;
	std::vector<IObject *>	objs;

	if (ac != 2) {
		std::cout << "Usage ./mod1 filename" << std::endl;
		return (0);
	}
	win = new CocoaWin(800, 600);
	land = new Landscape(std::string(av[1]));
	objs.push_back(land);
	win->loop(objs);
	(void)ac;
	(void)av;
	delete win;
	delete land;
	return (0);
}
