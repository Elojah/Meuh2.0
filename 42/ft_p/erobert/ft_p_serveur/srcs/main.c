/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 17:07:39 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 14:29:35 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include "serveur.h"

static int				ft_server_create(int port)
{
	int					sock;
	struct protoent		*p;
	struct sockaddr_in	sin;

	p = getprotobyname("tcp");
	if (!p)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, p->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htons(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("error: bind", 2);
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}

static int				ft_usage(char *str)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" [port]", 2);
	return (-1);
}

int						main(int ac, char **av)
{
	int					ssock;
	int					csock;
	unsigned int		len;
	struct sockaddr_in	csin;
	pid_t				father;

	if (ac != 2)
		return (ft_usage(av[0]));
	ssock = ft_server_create(ft_atoi(av[1]));
	if (ssock == -1)
		return (-1);
	while ((csock = accept(ssock, (struct sockaddr *)&csin, &len)))
	{
		ft_putendl_fd("comlink: activated", 1);
		father = fork();
		if (!father)
		{
			ft_serveur_loop(csock);
			if (close(csock) != -1)
				ft_putendl_fd("comlink: close", 1);
			break ;
		}
	}
	close(ssock);
	return (0);
}
