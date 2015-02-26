#include "X11Win.hpp"
#include "IObject.hpp"

int		main(int ac, char **av) {
	X11Win		win(800, 600);
	std::vector<IObject>	objs;

	win.loop(objs);
	(void)ac;
	(void)av;
	return (0);
}
