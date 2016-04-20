/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:32:34 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/20 02:03:39 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

static void	exec_ls(char **paramTMP, t_client_data *client_data)
{
	static const char	*const param[] = {"/bin/ls", NULL};

	(void)paramTMP;
	ft_putstr("EXEC:\tls\n");
	pid_t pid = fork();
	if (pid == 0)
	{
		dup2(client_data->cs, 1);
		execl((char *)"/bin/ls", (const char *)param);
		exit(0);
	}
	else if (pid > 0)
	{
		wait4(pid, NULL, 0, NULL);
		SUCCESS;
	}
}

static void	exec_get(char **param, t_client_data *client_data)
{
	(void)param;
	(void)client_data;
}


static void	exec_pwd(char **param, t_client_data *client_data)
{
	(void)param;
	ft_putstr("EXEC:\tpwd\n");
	ft_putstr_fd(client_data->current_path, client_data->cs);
	write(client_data->cs, "\n", 1);
	SUCCESS;
}

void			exec_cmd(t_cmd cmd, char **msg, t_client_data *client_data)
{
	static const t_cmd_ft	cmd_dispatcher[] =
	{
		&exec_ls,
		&exec_cd,
		&exec_get,
		&exec_put,
		&exec_pwd
	};

	ft_putstr("EXEC CMD\n");
	ft_putnbr((int)cmd);
	if (cmd == NONE)
		write(client_data->cs, "Unrecognized command\nERROR\0", 27);
	else if (cmd == QUIT)
		write(client_data->cs, "QUIT\0", 21);
	else
		cmd_dispatcher[(int)cmd](msg, client_data);
}
