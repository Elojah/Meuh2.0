/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:42:26 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/06 14:01:12 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string.h>

static void		write_socket(char *msg, int sock)
{
	write(sock, msg, strlen(msg));
}

static int		create_client(char *addr, int port)
{
	int sock;
	struct protoent	*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		write(2, "Connect error\n", 14);
		exit(2);
	}
	return (sock);
}

void		connect(char *addr, int port)
{
	int						sock;

	sock = create_client(addr, port);
	write_socket("TEST", sock);
	close(sock);
}
