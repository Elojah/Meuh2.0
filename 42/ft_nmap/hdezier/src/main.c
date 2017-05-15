/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:37:41 by leeios            #+#    #+#             */
/*   Updated: 2017/01/02 12:18:18 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_nmap.h"

static void	free_specs(t_spec *specs)
{
	free_list(&specs->ip_adresses);
}

static int	print_err(const t_err err)
{
	static const char	*err_msg[] = {
		"This feature is currently in progress, please try it later :)",
		"ft_nmap [OPTIONS]\n"
		"--help Print this help screen\n"
		"--ports ports to scan (eg: 1-10 or 1,2,3 or 1,5-15)\n"
		"--ip ip addresses to scan in dot format\n"
		"--file File name containing IP addresses to scan\n"
		"--speedup [250 max] number of parallel threads to use\n"
		"--scan SYN/NULL/FIN/XMAS/ACK/UDP\n",
		"Can't open device :(",
		"Can't find this ip/hostname",
		"Can't set valid socket options"
	};
	if (err == NONE)
		return (0);
	else
		printf("%s\n", err_msg[err]);
	return (-1);
}

int			main(int ac, char **av)
{
	t_err	error;
	t_spec	specs;

	error = scan_args(ac, av, &specs);
	if (error != NONE)
		return (print_err(error));
	error = launch_scan(&specs);
	if (error != NONE)
		return (print_err(error));
	free_specs(&specs);
	return (0);
}
