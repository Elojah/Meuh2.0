/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:12:41 by leeios            #+#    #+#             */
/*   Updated: 2016/12/29 14:35:08 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_nmap.h"
#include "libstr.h"

static t_err	set_args_map(char *key, char *value, t_args_map *args_map)
{
	if (ft_strcmp(key, "help") == 0)
		return (t_err::HELP);
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
		return (t_err::HELP);
	return (t_err::NONE);
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
				return (t_err::HELP);
			error = set_args_map(av[i] + 2, av[i + 1], args_map);
			if (error != t_err::NONE)
				return (error);
			++i;
		}
		else
			return (t_err::HELP);
	}
	return (t_err::NONE);
}

t_err		scan_args(int ac, char **av, t_spec *specs)
{
	(void)ac;
	(void)av;
	t_err		error;
	t_args_map	args_map;

	error = args_to_map(ac, av, &args_map);
	if (error != t_err::NONE)
		return (error);

	// Default values
	specs->n_threads = 0;
	specs->scan = t_scan_types::SYN | t_scan_types::NULL_SCAN
				| t_scan_types::ACK | t_scan_types::FIN
				| t_scan_types::XMAS | t_scan_types::UDP;
	specs->ports.ranges = (t_range *)malloc(1 * sizeof(t_range));
	specs->ports.ranges[0] = (t_range){1, 1024};

	return (error);
}
