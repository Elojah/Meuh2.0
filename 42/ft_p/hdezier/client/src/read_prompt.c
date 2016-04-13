/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:52:30 by leeios            #+#    #+#             */
/*   Updated: 2016/04/13 21:55:37 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "client.h"
#include "libft.h"

static char		*read_user(void)
{
	// char	*buf;
	// int		r;

	// buf = (char *)ft_memalloc((BUFF_SIZE + 1) * sizeof(char));
	// r = read(0, buf, BUFF_SIZE);
	// buf[r] = '\0';
	// return (buf);
	char		**msg;

	msg = NULL;
	ft_get_line(0, msg);
	return (*msg);
}

static void	send_data(int sock, char *s)
{
	int		size_data;

	size_data = ft_strlen(s);
	if (size_data > 1024)
	{
		ft_putstr_fd((char *)"Message is too big", sock);
		return ;
	}
	ft_putnbr_fd(size_data, sock);
	write(sock, (char *)"\n", 1);
	ft_putstr_fd(s, sock);
}

void		read_prompt(int sock)
{
	char	*s;

	while (1)
	{
		write(1, "$>", 2);
		s = read_user();
		send_data(sock, s);
		// read(sock, s, BUFF_SIZE);
		ft_putstr(s);
		free(s);
	}
}
