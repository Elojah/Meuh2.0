/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 18:27:52 by jchichep          #+#    #+#             */
/*   Updated: 2014/06/16 01:58:47 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "client.h"

void					lvl_1_init(int ac, char **av)
{
	t_env				e;
	int					csock;
	char				*line;
	int					r;

	if (ft_lexer(ac, av, &e))
		_exit(-1);
	csock = ft_client_create(e.hostname, ft_atoi(e.port));
	if (csock == -1)
		_exit(-1);
	if ((r = get_next_line(csock, &line)) < 1)
		_exit(ft_print_result("error: read", "", -1));
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\n", 1);
	ft_send(e.team_name, csock);
	if ((r = get_next_line(csock, &line)) < 1)
		_exit(ft_print_result("error: read", "", -1));
	if ((r = ft_atoi(line)) < 1)
		_exit(ft_print_result("error: no such team or max client", "", -1));
	ft_putendl_fd(line, 1);
	get_next_line(csock, &line);
	ft_putendl_fd(line, 1);
	lvl_1(ac, av, csock);
	close(csock);
	_exit(0);
}
