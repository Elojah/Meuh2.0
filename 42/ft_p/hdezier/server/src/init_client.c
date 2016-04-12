/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:04:35 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/12 19:45:11 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include "libft.h"

static t_client_data	*clients_data[MAX_CLIENT];

e_bool						init_client(pid_t child)
{
	static int				nb_client = 0;
	t_client_data			*new_client;

	if (nb_client >= MAX_CLIENT)
		return (FALSE);
	new_client = (t_client_data *)malloc(sizeof(t_client_data));
	new_client->id = nb_client;
	new_client->child = child;
	ft_strcpy((char *)DEFAULT_PATH, new_client->current_path);
	clients_data[nb_client] = new_client;
	++nb_client;
	return (TRUE);
}

