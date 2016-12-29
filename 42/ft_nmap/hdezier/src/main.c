/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:37:41 by leeios            #+#    #+#             */
/*   Updated: 2016/12/29 14:00:52 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_nmap.h"

static int	print_err(const t_err err)
{
	static const char	*err_msg[] = {
		"ft_nmap [OPTIONS]"
		"--help Print this help screen"
		"--ports ports to scan (eg: 1-10 or 1,2,3 or 1,5-15)"
		"--ip ip addresses to scan in dot format"
		"--file File name containing IP addresses to scan"
		"--speedup [250 max] number of parallel threads to use"
		"--scan SYN/NULL/FIN/XMAS/ACK/UDP",
		""
	};
	if (err == t_err::HELP || t_err::ARGS_WRONG_FORMAT)
		printf("%s\n", err_msg[0]);
	else if (err == t_err::NONE)
		return (0);
	return (-1);
}

int			main(int ac, char **av)
{
	t_err	error;
	t_spec	specs;

	error = scan_args(ac, av, &specs);
	if (error != t_err::NONE)
		return (print_err(error));
	return (0);
}
