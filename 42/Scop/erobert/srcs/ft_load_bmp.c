/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:22:29 by erobert           #+#    #+#             */
/*   Updated: 2015/05/11 15:30:38 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "scop.h"

int					ft_load_bmp(t_env *e, char *file)
{
	int				fd;
	unsigned char	header[54];
	unsigned int	data;
	unsigned int	width;
	unsigned int	height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read(fd, header, 54) != 54 || header[0] != 'B' || header[1] != 'M')
	{
		close(fd);
		return (ft_error("corrupt bmp file", -1));
	}
	data = *(int *)&(header[0x0A]);
	width = *(int *)&(header[0x12]);
	height = *(int *)&(header[0x16]);
	if (width * height * 3 > sizeof(e->texture))
		return (ft_error("bmp too large", -1));
	read(fd, e->texture, width * height * 3);
	return (close(fd));
}
