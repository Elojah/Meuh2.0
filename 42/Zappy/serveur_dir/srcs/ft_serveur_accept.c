/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_serveur_accept.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 16:48:56 by erobert           #+#    #+#             */
/*   Updated: 2015/06/12 16:58:47 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>
#include "serveur.h"

static void				ft_gfxclt_accept(t_env *e, int sock)
{
	int					i;

	ft_putmsz_fd(e, sock);
	ft_putsgt_fd(e, sock);
	ft_putbct_fd(e, -1, -1, sock);
	i = 0;
	while (i < TEAM_MAX && e->team_name[i][0])
	{
		ft_putstr_fd("tna ", sock);
		ft_putendl_fd(e->team_name[i++], sock);
	}
	i = -1;
	while (++i < e->mfds)
	{
		if (e->fds[i].type == PLAYER)
			ft_putpnw_fd(e, i, sock);
	}
	i = -1;
	while (++i < e->mfds)
	{
		if (e->fds[i].type == PLYEGG)
			ft_putenw_fd(e, i, sock);
	}
	e->fds[sock].fct_read = ft_gfxclt_read;
	e->gfx = sock;
}

static void				ft_player_init(t_env *e, int sock)
{
	struct timeval		tp;
	int					i;

	gettimeofday(&tp, NULL);
	e->fds[sock].cmd = E_CMD;
	e->fds[sock].level = '1';
	e->fds[sock].resource[FOOD] = 10;
	i = 0;
	while (++i < 7)
		e->fds[sock].resource[i] = 0;
	e->fds[sock].pos[0] = rand() % e->width;
	e->fds[sock].pos[1] = rand() % e->height;
	e->trantor[e->fds[sock].pos[0]][e->fds[sock].pos[1]].resource[PLAY]++;
	e->fds[sock].fct_read = ft_player_read;
	e->fds[sock].hp.tv_sec = tp.tv_sec + 126 / e->time;
	e->fds[sock].hp.tv_usec = tp.tv_usec;
}

static int				ft_player_accept(t_env *e, int sock, int i)
{
	ft_putnbr_fd(e->client_nb[i], sock);
	ft_putendl_fd("", sock);
	ft_putnbr_fd(e->width, sock);
	ft_putstr_fd(" ", sock);
	ft_putnbr_fd(e->height, sock);
	ft_putendl_fd("", sock);
	if (e->client_nb[i] > 0)
	{
		e->fds[sock].team_number = i;
		e->client_nb[i]--;
	}
	else
		return (ft_print_result("error: team full", "", -1));
	ft_player_init(e, sock);
	return (0);
}

static int				ft_client_accept(t_env *e, int sock)
{
	char				buf[BUF_SIZE];
	int					r;
	int					i;

	r = read(sock, buf, BUF_SIZE);
	if (r < 1)
		return (ft_print_result("error: read client", "", -1));
	if (ft_linecmp(buf, "GRAPHIC") == 0)
	{
		e->fds[sock].type = GFXCLT;
		ft_gfxclt_accept(e, sock);
		return (0);
	}
	i = 0;
	while (i < TEAM_MAX && ft_linecmp(buf, e->team_name[i]))
		i++;
	if (i == TEAM_MAX)
	{
		ft_putendl_fd("ko", sock);
		return (ft_print_result("error: team_name doesn't exit", "", -1));
	}
	e->fds[sock].type = PLAYER;
	return (ft_player_accept(e, sock, i));
}

void					ft_serveur_accept(t_env *e, int ssock)
{
	int					csock;
	struct sockaddr_in	csin;
	unsigned int		len;
	int					gsock;

	len = sizeof(csin);
	csock = accept(ssock, (struct sockaddr *)&csin, &len);
	if (csock < 0)
		return ;
	ft_putstr("comlink ");
	ft_putnbr(csock);
	ft_putendl(": activated");
	ft_putendl_fd("BIENVENUE", csock);
	if (ft_client_accept(e, csock) || e->fds[csock].type == GFXCLT)
		return ;
	gsock = 0;
	while (gsock < e->mfds && e->fds[gsock].type != GFXCLT)
		gsock++;
	if (gsock == e->mfds)
		return ;
	ft_putpnw_fd(e, csock, gsock);
}
