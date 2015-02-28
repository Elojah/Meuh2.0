#include "X11Win.hpp"
#include "Landscape.hpp"
#include "IObject.hpp"

int		main(int ac, char **av) {
	X11Win		win(800, 600);
	Landscape	land("./test/demo5.mod1");
	std::vector<IObject *>	objs;

	objs.push_back(&land);
	win.loop(objs);
	(void)ac;
	(void)av;
	return (0);
}
