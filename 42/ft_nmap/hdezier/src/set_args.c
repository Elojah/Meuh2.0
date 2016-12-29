/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 18:11:25 by leeios            #+#    #+#             */
/*   Updated: 2016/12/29 21:29:36 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_nmap.h"

t_err		set_args(const t_args_map *args_map, t_spec *specs)
{
	t_err	error;

	error = set_ports(args_map->ports, &specs->ports);
	if (error != NONE)
		return (error);
	// if (args_map->ip != 0x0)
	// 	specs->ip = args_map->ip;
	// else
	// 	specs->ip = 0x0;
	// if (args_map->file != 0x0)
	// 	specs->file = args_map->file;
	// else
	// 	specs->file = 0x0;
	// if (args_map->speedup != 0x0)
	// 	specs->speedup = args_map->speedup;
	// else
	// 	specs->speedup = 0x0;
	// if (args_map->scan != 0x0)
	// 	specs->scan = args_map->scan;
	// else
	// 	specs->scan = 0x0;
	return (error);
}
