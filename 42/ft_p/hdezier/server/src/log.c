/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 21:27:47 by leeios            #+#    #+#             */
/*   Updated: 2016/04/13 21:52:58 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

void		init_log(void)
{
	int		fd;

	fd = open((char *)"./data/log.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	dup2(fd, 1);
}

void		write_log(char *s, const t_client_data *client_data)
{
	return ;
	write(1, "[", 1);
	if (client_data != NULL)
		ft_putstr(client_data->current_path);
	write(1, "]", 1);
	ft_putstr(s);
}
