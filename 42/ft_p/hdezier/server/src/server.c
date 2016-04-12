/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:42:11 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/12 19:41:57 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static e_cmd	is_cmd(char *s)
{
	static const char	*const cmds[] =
	{
		"ls",
		"cd",
		"get",
		"put",
		"pwd",
		"quit",
	};
	int			i;

	i = -1;
	while (++i < NONE)
	{
		if (ft_strcmp(s, cmds[i]) == 0)
			return ((e_cmd)i);
	}
	return (NONE);
}

static char		*read_socket(int cs)
{
	char	**result;

	result = NULL;
	ft_get_line(cs, result);
	return (*result);
}

static e_bool		process_msg(int cs)
{
	char		*msg;
	char		**split_msg;
	e_cmd		cmd;
	msg = read_socket(cs);
	close(cs);
	if (msg == NULL)
		return (TRUE);
	split_msg = ft_strsplit(msg, ' ');
	free(msg);
	cmd = is_cmd(split_msg[0]);
	if (cmd == NONE)
	{
		write(2, msg, ft_strlen(msg));
		write(2, " is not a valid command.\n", 25);
	}
	exec_cmd(cmd, split_msg);
	ft_free_array_str(split_msg);
	return (cmd == QUIT ? FALSE : TRUE);
}

static int		init_server(int port)
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

void			listen_port(int port)
{
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				child;

	sock = init_server(port);
	if (sock == -1)
		return ;
	while (1)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
		child = fork();
		if (child == 0)
		{
			if (init_client(child) == TRUE)
			{
				while (process_msg(cs) == TRUE)
					;
			}
		}
	}
	close(sock);
}
