/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 01:23:22 by leeios            #+#    #+#             */
/*   Updated: 2016/04/20 02:02:27 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <fcntl.h>

static void		write_file(int fd, t_client_data *client_data, int i)
{
	char	buf[1024];
	int		r;

	while (i > 0)
	{
		r = read(client_data->cs, buf, i > 1024 ? 1024 : i);
		write(fd, buf, r);
		i -= 1024;
	}
}

static t_bool	read_file(char *filename, t_client_data *client_data)
{
	char	size_data[10];
	int		i;
	int		r;
	int		fd;

	i = -1;
	r = 1;
	fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU);
	while (++i < 9 && r > 0)
	{
		r = read(client_data->cs, &(size_data[i]), 1);
		if (size_data[i] == '.')
		{
			size_data[i] = '\0';
			i = ft_atoi(size_data);
			if (i == 0)
				return (FALSE);
			write_file(fd, client_data, i);
		}
		else if (size_data[i] < '0' || size_data[i] > '9')
			return (FALSE);
	}
	return (TRUE);
}

void			exec_put(char **param, t_client_data *client_data)
{
	int		i;

	i = 0;
	ft_putstr("EXEC:\tput\n");
	while (param[++i] != NULL)
	{
		ft_putstr(param[i]);
		ft_putstr("\treceiving...\n");
		if (read_file(param[i], client_data) == FALSE)
			ft_putstr("Error receiving file \n");
		else
			ft_putstr("File received !\n");
	}
	SUCCESS;
}
