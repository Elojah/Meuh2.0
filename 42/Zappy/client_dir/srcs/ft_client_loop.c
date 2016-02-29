/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 15:13:05 by erobert           #+#    #+#             */
/*   Updated: 2014/06/27 11:19:52 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			lvl_1(int ac, char **av, int sock)
{
	char		*line;
	int			inc;

	inc = 1;
	(void)ac;
	(void)av;
	line = "";
	while (line && ft_strncmp(line, "mort", 4) != 0)
	{
		ft_send("avance", sock);
		get_next_line(sock, &line);
		if (ft_strncmp(line, "mort", 4) == 0)
			break ;
		if (inc == 1)
		{
			ft_send("incantation", sock);
			get_next_line(sock, &line);
			if (ft_strncmp(line, "ko", 2) != 0)
				--inc;
		}
	}
	close(sock);
	_exit(0);
}
