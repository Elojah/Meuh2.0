#include "main.h"
# include "IGui_mlx.h"

int	main()
{
	IGui_mlx	test;

	test.init_window();
	test.loop();
	return(0);
}

