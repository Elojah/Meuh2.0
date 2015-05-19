#include "Game.hpp"

static void	exec(void) {
	Game	g;

	g.launch();
	g.loop();
}

int			main(int ac, char **av) {
	(void)ac;
	(void)av;
	exec();
	return (0);
}
