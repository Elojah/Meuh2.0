/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 17:07:39 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 14:15:19 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "client.h"

static int				ft_client_create(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("error: connect", 2);
		return (-1);
	}
	return (sock);
}

static int				ft_usage(char *str)
{
	ft_putstr_fd("usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" [addr] [port]", 2);
	return (-1);
}

int						main(int ac, char **av)
{
	int					csock;

	if (ac != 3)
		return (ft_usage(av[0]));
	csock = ft_client_create(av[1], ft_atoi(av[2]));
	if (csock == -1)
		return (-1);
	ft_client_loop(csock, av);
	close(csock);
	return (0);
}
