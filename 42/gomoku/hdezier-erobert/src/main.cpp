#include "GameManager.hpp"

static void	exec(void)
{
	GameManager		g;

	g.init();
	g.loop();
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	exec();
	return (0);
}
