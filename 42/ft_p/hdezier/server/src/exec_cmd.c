/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:32:34 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/12 18:49:32 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	exec_ls(char **param)
{
	(void)param;
}

static void	exec_cd(char **param)
{
	(void)param;
}

static void	exec_get(char **param)
{
	(void)param;
}

static void	exec_put(char **param)
{
	(void)param;
}

static void	exec_pwd(char **param)
{
	(void)param;
}

void		exec_cmd(e_cmd cmd, char **msg)
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
	cmd_dispatcher[(int)cmd](msg);
}
