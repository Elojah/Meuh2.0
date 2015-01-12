#include "ft_minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void		sh_cd(t_cmd *cmd)
{
	char	*dir;

	if (!cmd->args[1])
		/*go home*/
		return ;
	dir = ft_strjoin(cmd->current_dir, "/");
	dir = ft_strjoin(dir, cmd->args[1]);
	if (chdir(dir) < 0)
	{
		ft_putstr_fd("Can't access to this directory: ", 2);
		ft_putendl_fd(cmd->args[1], 2);
	}
	free(dir);
}

void		sh_setenv(t_cmd *cmd)
{
	int		i;
	char	**s_env;
	char	**s_cmd;

	i = -1;
	while (cmd->env[++i])
	{
		s_env = ft_strsplit(cmd->env[i], '=');
		s_cmd = ft_strsplit(cmd->args[1], '=');
			printf("env: %s -- arg: %s\n", s_env[0], s_cmd[0]);
		if (!ft_strcmp(s_env[0], s_cmd[0]))
		{
			ft_strcpy(cmd->env[i], cmd->args[1]);
			printf("new env: %s\n", cmd->env[i]);
			return ;
		}
	}
	printf("ADD__env: %s -- arg: %s\n", cmd->env[i], cmd->args[1]);
	cmd->env[i] = ft_strdup(cmd->args[1]);
	cmd->env[i + 1] = NULL;
}

void		sh_unsetenv(t_cmd *cmd)
{
	int		i;
	char	**s_env;

	i = -1;
	while (cmd->env[++i])
	{
		s_env = ft_strsplit(cmd->env[i], '=');
		if (!ft_strcmp(s_env[0], cmd->args[1]))
		{
			while (cmd->env[++i])
				cmd->env[i] = cmd->env[i + 1];
			return ;
		}
	}
}

void		sh_env(t_cmd *cmd)
{
	int		i;

	i = -1;
	while (cmd->env[++i])
		ft_putendl(cmd->env[i]);
}

void		sh_exit(t_cmd *cmd)
{
	cmd = cmd;
	ft_exit(1, "See ya !");
}

