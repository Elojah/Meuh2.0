/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:32:34 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/13 17:19:12 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

static void	exec_ls(char **param, t_client_data *client_data)
{
	(void)param;
	ft_putstr_fd(client_data->current_path, client_data->cs);
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
