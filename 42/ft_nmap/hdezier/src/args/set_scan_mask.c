/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scan_mask.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:49:37 by leeios            #+#    #+#             */
/*   Updated: 2016/12/31 11:53:51 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "libstr.h"
#include <stdio.h>

static t_err	set_scan_mask_bit(char *val, t_scan_mask *mask)
{
	if (ft_strcmp(val, "SYN"))
		*mask = *mask & SYN;
	else if (ft_strcmp(val, "NULL"))
		*mask = *mask & NULL_SCAN;
	else if (ft_strcmp(val, "ACK"))
		*mask = *mask & ACK;
	else if (ft_strcmp(val, "FIN"))
		*mask = *mask & FIN;
	else if (ft_strcmp(val, "XMAS"))
		*mask = *mask & XMAS;
	else if (ft_strcmp(val, "UDP"))
		*mask = *mask & UDP;
	else
		return (HELP);
	return (NONE);
}

t_err			set_scan_mask(char *arg, t_scan_mask *mask)
{
	char		*arg_scan;

	if (arg == NULL)
		*mask = SYN | NULL_SCAN | ACK | FIN | XMAS | UDP;
	else
	{
		arg_scan = get_next_token(&arg, '/');
		if (arg_scan == NULL)
			return (HELP);
		while (arg_scan != NULL)
		{
			set_scan_mask_bit(arg_scan, mask);
			arg_scan = get_next_token(&arg, '/');
		}
	}
	return (NONE);
}

void			print_scan_mask(t_scan_mask *mask)
{
	if (*mask & SYN)
		printf(" SYN");
	if (*mask & NULL_SCAN)
		printf(" NULL");
	if (*mask & ACK)
		printf(" ACK");
	if (*mask & FIN)
		printf(" FIN");
	if (*mask & XMAS)
		printf(" XMAS");
	if (*mask & UDP)
		printf(" UDP");
}
