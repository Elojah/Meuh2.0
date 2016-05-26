/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:15:11 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/26 17:16:25 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

static void		print_err(t_err err)
{
	const static char	*const err_msg[] =
	{
		"",
		"ERR_MMAP",
		"ERR_ARG_NUMBER",
		"ERR_FILE_OPEN",
		"ERR_FILE_STAT"
	};
	if (err > 0 && err < E_ERR)
		printf("%s\n", err_msg[err]);
}

static t_err		exec(char *filename)
{
	int				fd;
	char			*file;
	struct stat		buf;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_FILE_OPEN);
	if (fstat(fd, &buf) < 0)
		return (ERR_FILE_STAT);
	file = (char *)mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file == MAP_FAILED)
		return (ERR_MMAP);
	return (nm((char *)file));
}

int			main(int ac, char **av)
{
	if (ac != 2)
		print_err(ERR_ARG_NUMBER);
	else
		print_err(exec(av[1]));
	return (0);
}
