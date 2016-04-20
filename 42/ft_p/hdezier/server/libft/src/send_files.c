/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:47:37 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/20 19:17:14 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>

static void	write_file(char *filename, int sock)
{
	int					fd;
	int					r;
	char				buf[1024];
	struct stat			st;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		write(sock, "0.", 2);
	stat(filename, &st);
	ft_putnbr_fd(st.st_size, sock);
	ft_putstr_fd(".", sock);
	while ((r = read(fd, buf, 1024)) > 0)
		write(sock, buf, r);
	ft_putstr("File sent !\n");
}

void		send_files(int sock, char *s)
{
	char	**params;
	int		i;

	write(1, "Sending files...\n", 17);
	params = ft_strsplit(s, ' ');
	i = 0;
	while (params[++i] != NULL)
	{
		ft_putstr(params[i]);
		ft_putstr("\tsending...\n");
		write_file(params[i], sock);
	}
}
