/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:42:11 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/06 14:02:52 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static void		read_socket(int cs)
{
	int		r;
	char	buf[1024];

	r = read(cs, buf, 1024);
	if (r > 0)
	{
		;
	}
}

static int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		write(2, "Binding error\n", 14);
		return (-1);
	}
	listen(sock, 42);
	return (sock);
}

void			listen(int port)
{
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;

	sock = create_server(port);
	if (sock == -1){}
	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	read_socket(cs);
	// Use cs here
	close(cs);
	close(sock);
}
