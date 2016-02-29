/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 17:07:39 by erobert           #+#    #+#             */
/*   Updated: 2015/06/12 16:21:35 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "serveur.h"

static int				ft_server_create(int port)
{
	int					sock;
	struct protoent		*p;
	struct sockaddr_in	sin;

	p = getprotobyname("tcp");
	if (!p)
		return (ft_print_result("error: getprotobyname", "", -1));
	sock = socket(PF_INET, SOCK_STREAM, p->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htons(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (ft_print_result("error: bind", "", -1));
	listen(sock, 42);
	return (sock);
}

static int				ft_env_init(t_env *e)
{
	struct rlimit		rlp;
	int					i;

	if (getrlimit(RLIMIT_NOFILE, &rlp))
		return (ft_print_result("error: getrlimit", "", -1));
	e->mfds = rlp.rlim_cur;
	e->fds = malloc(sizeof(t_fd) * e->mfds);
	if (!e->fds)
		return (ft_print_result("error: malloc [e->fds]", "", -1));
	i = -1;
	while (++i < e->mfds)
	{
		ft_bzero(e->fds[i].buf_read, BUF_SIZE);
		ft_bzero(e->fds[i].buf_write, BUF_SIZE);
		e->fds[i].type = 0;
		e->fds[i].cmd = -1;
		e->fds[i].fct_read = NULL;
		e->fds[i].fct_write = NULL;
	}
	return (0);
}

int						main(int ac, char **av)
{
	int					sock;
	t_env				e;

	if (ft_lexer(ac, av, &e))
		return (-1);
	if (ft_env_init(&e))
		return (-1);
	sock = ft_server_create(ft_atoi(e.port));
	if (sock == -1)
		return (-1);
	if (ft_trantor_init(&e))
		return (-1);
	ft_putendl_fd("init: ok", 1);
	ft_putstr_fd(" -client port: ", 1);
	ft_putendl_fd(e.port, 1);
	ft_putstr_fd(" -gfx port: ", 1);
	ft_putendl_fd(e.port, 1);
	ft_serveur_loop(&e, sock);
	close(sock);
	return (0);
}
