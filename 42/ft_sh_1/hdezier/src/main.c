#include "ft_minishell.h"
#include <unistd.h>

static void	import_path(t_cmd *cmd)
{
	extern char		**environ;
	int				i;

	i = -1;
	while (environ[++i])
		;
	cmd->env = (char **)ft_memalloc(i * sizeof(char *));
	while (--i >= 0)
	{
		cmd->env[i] = (char *)ft_memalloc(BUFF_SIZE * sizeof(char));
		ft_strncpy(cmd->env[i], environ[i], BUFF_SIZE);
	}
}

static void	main_loop(void)
{
	t_cmd			cmd;
	char			*s;

	import_path(&cmd);
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
