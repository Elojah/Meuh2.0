/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:32:34 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/13 21:16:20 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

static void	exec_ls(char **paramTMP, t_client_data *client_data)
{
	static const char	*const param[] = {"/bin/ls", NULL};
	int							fd;

	(void)paramTMP;
	(void)client_data;
	fd = open("outfile", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	pid_t pid = fork();
	if (pid == 0) {
		dup2(fd, STDOUT_FILENO);
		close(fd);
		execl((char *)"ls", (const char *)param);
	}
	else if (pid > 0)
		wait(NULL);
}

static void	exec_cd(char **param, t_client_data *client_data)
{
	(void)param;
	(void)client_data;
}

static void	exec_get(char **param, t_client_data *client_data)
{
	(void)param;
	(void)client_data;
}

static void	exec_put(char **param, t_client_data *client_data)
{
	(void)param;
	(void)client_data;
}

static void	exec_pwd(char **param, t_client_data *client_data)
{
	(void)param;
	ft_putstr_fd(client_data->current_path, client_data->cs);
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

	if (cmd == NONE || cmd == QUIT)
		return ;
	cmd_dispatcher[(int)cmd](msg, client_data);
}
