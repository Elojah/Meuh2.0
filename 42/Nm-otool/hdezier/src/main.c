/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:15:11 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/26 18:37:38 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void		ft_putstr_endl(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i++] != '\0')
		;
	write(1, s, i - 1);
	write(1, "\n", 1);
}

static void		print_err(t_err err)
{
	const static char			*const err_msg[] =
	{
		"",
		"ERR_MMAP",
		"ERR_ARG_NUMBER",
		"ERR_FILE_OPEN",
		"ERR_FILE_STAT"
	};
	if (err > 0 && err < E_ERR)
		ft_putstr_endl(err_msg[err]);
}

static t_err		exec(const char *filename)
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
	int		i;

	if (ac == 1)
		print_err(exec("a.out"));
	else
	{
		i = 0;
		while (++i < ac)
			print_err(exec(av[i]));
	}
	return (0);
}
