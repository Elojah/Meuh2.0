/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pondeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:12:56 by jchichep          #+#    #+#             */
/*   Updated: 2014/06/27 11:12:10 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"client.h"

void			duplic_client(int ac, char **av, int sock, int left)
{
	int			needed;
	char		*line;

	needed = 8 - left;
	while (left-- > 0)
		new_client(ac, av, 1);
	left = needed;
	line = "";
	while (left-- > 0)
	{
		ft_send("fork", sock);
		get_next_line(sock, &line);
	}
}

void			pondeur(int sock, int left, int ac, char **av)
{
	char		*line;
	int			connect;

	duplic_client(ac, av, sock, left);
	line = "";
	while (line && ft_strncmp(line, "mort", 4) != 0)
	{
		ft_send("avance", sock);
		get_next_line(sock, &line);
		if (ft_strncmp(line, "mort", 4) == 0)
			return ;
		ft_send("connect_nbr", sock);
		get_next_line(sock, &line);
		if (ft_strncmp(line, "mort", 4) == 0)
			return ;
		connect = ft_atoi(line);
		while (connect-- > 1)
			new_client(ac, av, 1);
	}
}

void			start_pondeur(int ac, char **av, int r, int csock)
{
	char *line;

	get_next_line(csock, &line);
	ft_putendl_fd(line, 1);
	pondeur(csock, r - 1, ac, av);
	close(csock);
}

void			pondeur_init(int ac, char **av, int new)
{
	t_env		e;
	int			csock;
	char		*line;
	int			r;

	if (ft_lexer(ac, av, &e)
		|| (csock = ft_client_create(e.hostname, ft_atoi(e.port))) == -1)
		return ;
	if ((r = get_next_line(csock, &line)) < 1)
	{
		ft_print_result("error: read", "", -1);
		return ;
	}
	ft_putendl_fd(line, 1);
	ft_send(e.team_name, csock);
	if ((r = get_next_line(csock, &line)) < 1
		|| (r = ft_atoi(line)) < 1)
	{
		ft_print_result("error: no such team or max client error", "", -1);
		return ;
	}
	if (r > 9 || new == 0)
		r = 9;
	ft_putendl_fd(line, 1);
	start_pondeur(ac, av, r, csock);
}
