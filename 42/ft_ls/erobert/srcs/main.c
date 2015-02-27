/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 18:57:28 by erobert           #+#    #+#             */
/*   Updated: 2015/02/26 15:17:03 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <dirent.h>
#include "ft_ls.h"

static void			ft_nofile_nodir(int ac, char **av, int i, int *arg)
{
	char			*tmp;
	int				j;
	int				k;

	j = i;
	while (j++ < ac - 1)
	{
		k = i;
		while (k < ac - 1)
		{
			if (ft_strcmp(av[k], av[k + 1]) > 0)
			{
				tmp = av[k];
				av[k] = av[k + 1];
				av[k + 1] = tmp;
			}
			k++;
		}
	}
	while (i < ac)
	{
		if (!opendir(av[i]) && !ft_printfile(av[i], arg, 0))
			ft_notopen(av[i]);
		i++;
	}
}

static int			ft_filearg(int ac, char **av, int i, int *arg)
{
	char			*tmp;
	int				k;

	k = 0;
	while (i < ac)
	{
		tmp = av[i];
		if (*tmp == '/')
			tmp = ft_strjoin("/", av[i]);
		if (!opendir(av[i]) && ft_printfile(tmp, arg, 1))
			k = 1;
		i++;
	}
	return (k);
}

static void			ft_dirarg(int ac, char **av, int i, int *arg)
{
	int				j;
	int				k;

	j = i;
	k = ft_filearg(ac, av, i, arg);
	while (i < ac)
	{
		if (!opendir(av[i]))
			;
		else if (arg[MR])
			ft_roption(av[i], arg);
		else
		{
			if (k++)
				ft_putendl("");
			if (j + 1 < ac)
			{
				ft_putstr(av[i]);
				ft_putendl(":");
			}
			ft_no_roption(av[i], arg);
		}
		i++;
	}
}

static int			ft_afterarg(int ac, char **av, int i, int *arg)
{
	ft_nofile_nodir(ac, av, i, arg);
	ft_dirarg(ac, av, i, arg);
	return (0);
}

int					main(int ac, char **av)
{
	static int		arg[7] = {0, 0, 0, 0, 0, 0, 0};
	int				i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac && av[i][0] == '-' && ft_strcmp(av[i], "--"))
		{
			if (!av[i][1])
				break ;
			if (ft_checkarg(av[i], arg) != 'l')
				return (ft_illegal(ft_checkarg(av[i], arg)));
			i++;
		}
		if (i < ac && !ft_strcmp(av[i], "--"))
			i++;
	}
	if (ac == i)
	{
		if (arg[MR])
			return (ft_roption(".", arg));
		return (ft_no_roption(".", arg));
	}
	return (ft_afterarg(ac, av, i, arg));
}
