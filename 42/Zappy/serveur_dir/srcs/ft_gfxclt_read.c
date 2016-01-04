/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfxclt_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 18:54:08 by erobert           #+#    #+#             */
/*   Updated: 2014/06/26 17:50:26 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "serveur.h"

static void	ft_bctcmd(t_env *e, int sock, char *cmd)
{
	int		x;
	int		y;

	if (ft_strncmp("bct ", cmd, 4))
		return ;
	cmd += 4;
	x = ft_atoi(cmd);
	while (*cmd && *cmd != ' ')
		cmd++;
	if (!*cmd)
		return ;
	y = ft_atoi(cmd);
	if (x < 0 || y < 0 || x >= e->width || y >= e->height)
		return ;
	ft_putbct_fd(e, x, y, sock);
}

static void	ft_tnacmd(t_env *e, int sock, char *cmd)
{
	int		i;

	if (ft_linecmp("tna", cmd))
		return ;
	i = 0;
	while (i < TEAM_MAX && e->team_name[i][0])
	{
		ft_putstr_fd("tna ", sock);
		ft_putendl_fd(e->team_name[i++], sock);
	}
}

static void	ft_plycmd(t_env *e, int sock, char *cmd)
{
	if (ft_strncmp("ppo ", cmd, 4) == 0)
		ft_putppo_fd(e, ft_atoi(cmd + 4), sock);
	else if (ft_strncmp("plv ", cmd, 4) == 0)
		ft_putplv_fd(e, ft_atoi(cmd + 4), sock);
	else if (ft_strncmp("pin ", cmd, 4) == 0)
		ft_putpin_fd(e, ft_atoi(cmd + 4), sock);
}

static void	ft_sgtcmd(t_env *e, int sock, char *cmd)
{
	int		time;

	if (ft_linecmp("sgt", cmd) == 0)
		ft_putsgt_fd(e, sock);
	else if (ft_strncmp("sst ", cmd, 4) == 0)
	{
		time = ft_atoi(cmd + 4);
		if (time < 1)
			return ;
		e->time = time;
		ft_putsgt_fd(e, sock);
	}
}

void		ft_gfxclt_read(t_env *e, int sock)
{
	int		len;

	len = recv(sock, e->fds[sock].buf_read, BUF_SIZE - 1, 0);
	if (len > 0)
	{
		if (ft_linecmp("msz", e->fds[sock].buf_read) == 0)
			ft_putmsz_fd(e, sock);
		if (ft_linecmp("mct", e->fds[sock].buf_read) == 0)
			ft_putbct_fd(e, -1, -1, sock);
		ft_bctcmd(e, sock, e->fds[sock].buf_read);
		ft_tnacmd(e, sock, e->fds[sock].buf_read);
		ft_plycmd(e, sock, e->fds[sock].buf_read);
		ft_sgtcmd(e, sock, e->fds[sock].buf_read);
	}
	else
		ft_sock_close(e, sock);
}
