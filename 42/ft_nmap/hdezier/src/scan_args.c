/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:12:41 by leeios            #+#    #+#             */
/*   Updated: 2016/12/29 18:27:02 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_nmap.h"
#include "libstr.h"

static void		set_args_map_null(t_args_map *args_map)
{
	args_map->ports = 0x0;
	args_map->ip = 0x0;
	args_map->file = 0x0;
	args_map->speedup = 0x0;
	args_map->scan = 0x0;
}

static t_err	set_args_map(char *key, char *value, t_args_map *args_map)
{
	if (ft_strcmp(key, "help") == 0)
		return (HELP);
	else if (ft_strcmp(key, "ports") == 0)
		args_map->ports = value;
	else if (ft_strcmp(key, "ip") == 0)
		args_map->ip = value;
	else if (ft_strcmp(key, "file") == 0)
		args_map->file = value;
	else if (ft_strcmp(key, "speedup") == 0)
		args_map->speedup = value;
	else if (ft_strcmp(key, "scan") == 0)
		args_map->scan = value;
	else
		return (HELP);
	return (NONE);
}

static t_err	args_to_map(int ac, char **av, t_args_map *args_map)
{
	int		i;
	t_err	error;

	i = 0;
	while (++i < ac)
	{
		if (ft_strncmp(av[i], "--", 2) == 0)
		{
			if (i + 1 >= ac)
				return (HELP);
			error = set_args_map(av[i] + 2, av[i + 1], args_map);
			if (error != NONE)
				return (error);
			++i;
		}
		else
			return (HELP);
	}
	return (NONE);
}

t_err		scan_args(int ac, char **av, t_spec *specs)
{
	t_err		error;
	t_args_map	args_map;

	set_args_map_null(&args_map);
	error = args_to_map(ac, av, &args_map);
	if (error != NONE)
		return (error);
	error = set_args(&args_map, specs);
	return (error);

}
