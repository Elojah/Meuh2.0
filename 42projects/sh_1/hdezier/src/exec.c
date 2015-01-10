#include "ft_minishell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <errno.h>
#include <stdio.h>

void		exec_cmd(t_cmd *cmd)
{
	pid_t	f;
	int		status;

	ft_putstr_fd(cmd->exe, 1);
	f = fork();
	if (f == 0)
		execve(cmd->exe, cmd->args, cmd->env);
		//  == -1, "Command execution failed\n");
		// ft_exit(
	else
	{
		if (waitpid(f, &status, 0) == -1)
			ft_putstr_fd("Error waiting command execution", 2);
		if (!WIFEXITED(status))
			ft_putstr_fd("Command execution terminated unnormally\n", 2);
	}
	printf("errno: %d\n", errno);
}
