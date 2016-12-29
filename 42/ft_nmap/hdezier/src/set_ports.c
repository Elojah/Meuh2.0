/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ports.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:25:52 by leeios            #+#    #+#             */
/*   Updated: 2016/12/29 21:28:38 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "libstr.h"
#include "libmem.h"

static t_err	set_ports_mask(char *p, t_ports *ports)
{
	int		val;
	int		range_top;

	val = ft_uatoi(&p);
	if (val < 1 || val > 1024)
		return (HELP);
	if (*p == '\0')
		ports->n[val] = 1;
	else if (*p == '-')
	{
		++p;
		range_top = ft_uatoi(&p);
		if (range_top < val || range_top > 1024)
			return (HELP);
		while (val < range_top)
			ports->n[val++] = 1;
	}
	else
		return (HELP);
	return (NONE);
}

/*
* This is parsing !
*/
static char		*get_next_port(char **s)
{
	char		*token;

	token = *s;
	if (**s == '\0')
		return (0x0);
	while (**s != '\0' && **s != ',')
		++*s;
	if (**s == ',')
	{
		**s = '\0';
		++*s;
	}
	return (token);
}

t_err			set_ports(char *arg, t_ports *ports)
{
	t_err	error;
	char	*arg_port;

	if (arg == 0x0)
		ft_memset(ports, 1, 1024);
	else
	{
		ft_memset(ports, 0, 1024);
		arg_port = get_next_port(&arg);
		if (arg_port == 0x0)
			return (HELP);
		while (arg_port != 0x0)
		{
			error = set_ports_mask(arg_port, ports);
			if (error != NONE)
				return (error);
			arg_port = get_next_port(&arg);
		}
	}
	return (NONE);
}
