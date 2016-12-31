/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ports.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:25:52 by leeios            #+#    #+#             */
/*   Updated: 2016/12/31 11:59:26 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "libstr.h"
#include "libmem.h"
#include <stdlib.h>

static void		set_ports_mask_bit(unsigned int val, t_ports *ports)
{
	ports->n[val++] = 1;
	++ports->size;
}

static t_err	set_ports_mask(char *p, t_ports *ports)
{
	int		val;
	int		range_top;

	val = ft_uatoi(&p);
	if (val < 1 || val > 1024)
		return (HELP);
	if (*p == '\0')
		set_ports_mask_bit(val, ports);
	else if (*p == '-')
	{
		++p;
		range_top = ft_uatoi(&p);
		if (range_top < val || range_top > 1024)
			return (HELP);
		while (val < range_top)
			set_ports_mask_bit(val++, ports);
	}
	else
		return (HELP);
	return (NONE);
}

t_err			set_ports(char *arg, t_ports *ports)
{
	t_err	error;
	char	*arg_port;

	if (arg == NULL)
	{
		ft_memset(&ports->n, 1, 1024);
		ports->size = 1024;
		return (NONE);
	}
	ft_memset(&ports->n, 0, 1024);
	ports->size = 0;
	arg_port = get_next_token(&arg, ',');
	if (arg_port == NULL)
		return (HELP);
	while (arg_port != NULL)
	{
		error = set_ports_mask(arg_port, ports);
		if (error != NONE)
			return (error);
		arg_port = get_next_token(&arg, ',');
	}
	return (NONE);
}
