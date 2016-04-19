/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:52:30 by leeios            #+#    #+#             */
/*   Updated: 2016/04/19 18:04:29 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "client.h"
#include "libft.h"

static char		*read_user(void)
{
	char	*str;
	char	*tmp;
	char	buf[2];

	str = (char *)ft_memalloc(sizeof(*str));
	str[0] = '\0';
	buf[0] = ' ';
	buf[1] = '\0';
	while (*buf != '\n' && *buf != '\0')
	{
		read(0, buf, 1);
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
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
	write(sock, (char *)".", 1);
	ft_putstr_fd(s, sock);
}

static char	*receive_data(int sock)
{
	char	*str;
	char	*tmp;
	char	buf[2];

	str = (char *)ft_memalloc(sizeof(*str));
	str[0] = '\0';
	buf[0] = ' ';
	buf[1] = '\0';
	while (*buf != '\0')
	{
		read(sock, buf, 1);
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	return (str);
}

void		read_prompt(int sock)
{
	char	*s;

	while (1)
	{
		write(1, "$>", 2);
		s = read_user();
		send_data(sock, s);
		free(s);
		s = receive_data(sock);
		if (ft_strcmp(s, "QUIT") == 0)
		{
			free(s);
			return ;
		}
		ft_putstr(s);
		free(s);
		write(1, "\n", 1);
	}
}
