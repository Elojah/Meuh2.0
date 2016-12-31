/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:51:15 by leeios            #+#    #+#             */
/*   Updated: 2016/12/31 12:00:38 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "libstr.h"
#include <stdlib.h>

t_err		set_ip(char *arg, t_list *adresses)
{
	char	*arg_ip;

	init_list(adresses);
	if (arg == NULL)
		return (NONE);
	arg_ip = get_next_token(&arg, ',');
	if (arg_ip == NULL)
		return (HELP);
	while (arg_ip != NULL)
	{
		append(adresses, arg_ip);
		arg_ip = get_next_token(&arg, ',');
	}
	return (NONE);
}

t_err		set_ip_from_file(char *filename, t_list *adresses)
{
	(void)filename;
	(void)adresses;
	return (WIP);
}
