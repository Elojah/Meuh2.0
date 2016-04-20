/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 00:27:11 by leeios            #+#    #+#             */
/*   Updated: 2016/04/20 02:00:28 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

#include <fcntl.h>
#include <sys/stat.h>

static void	write_file(char *filename, int sock)
{
	static const int	end_of_file = -1;
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
	write(sock, &end_of_file, 1);
	ft_putstr("File sent !\n");
}

void		send_file(char *s, int sock)
{
	char	*sub;
	char	**params;
	int		i;

	sub = s;
	while (*sub == ' ')
		++sub;
	if (ft_strncmp(sub, (char *)"put ", 4) == 0)
	{
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
}
