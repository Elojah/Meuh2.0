#include "ft_minishell.h"
#include <unistd.h>

static void	main_loop(void)
{
	t_cmd			cmd;
	char			*s;

	while (1)
	{
		ft_putstr("$>");
		s = read_user();
		parse(&cmd, s);
		exec_cmd(&cmd);
	}
}

int		main()
{
	main_loop();
	return (0);
}
