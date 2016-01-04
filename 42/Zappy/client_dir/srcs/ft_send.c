/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:12:37 by erobert           #+#    #+#             */
/*   Updated: 2014/06/27 10:38:37 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include "client.h"

void		ft_send(char *str, int sock)
{
	size_t	len;

	str = ft_strjoin(str, "\n");
	len = ft_strlen(str);
	send(sock, str, len, 0);
	free(str);
}
