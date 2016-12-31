/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 18:11:25 by leeios            #+#    #+#             */
/*   Updated: 2016/12/30 16:48:36 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_nmap.h"
#include "libstr.h"

t_err		set_args(t_args_map *args_map, t_spec *specs)
{
	t_err	error;
	int		tmp;

	error = set_ports(args_map->ports, &specs->ports);
	if (error != NONE)
		return (error);
	error = set_ip(args_map->ip, &specs->ip_adresses);
	if (error != NONE)
		return (error);
	error = set_ip_from_file(args_map->file, &specs->ip_adresses);
	if (error != NONE)
		; // WIP
	if (args_map->speedup != NULL)
	{
		tmp = ft_uatoi(&args_map->speedup);
		if (tmp < 1 || tmp > 250)
			return (HELP);
		specs->n_threads = tmp;
	}
	else
		specs->n_threads = 0;
	error = set_scan_mask(args_map->scan, &specs->scan);
	if (error != NONE)
		return (error);
	return (NONE);
}
