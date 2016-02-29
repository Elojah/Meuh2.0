/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:42/Taskmaster/hdezier-rbernand/src/Log.cpp
/*   Created: 2015/08/15 13:01:29 by leeios            #+#    #+#             */
/*   Updated: 2015/08/29 06:36:21 by leeios           ###   ########.fr       */
=======
/*   Created: 2014/06/09 16:12:37 by erobert           #+#    #+#             */
/*   Updated: 2014/06/27 10:38:37 by jchichep         ###   ########.fr       */
>>>>>>> 3fb45b870d19ae0d4347e66467354b39b6a86867:42/Zappy/client_dir/srcs/ft_send.c
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include "client.h"

void		ft_send(char *str, int sock)
{
	size_t	len;

<<<<<<< HEAD:42/Taskmaster/hdezier-rbernand/src/Log.cpp
Log::Log(void) {
	;
}

Log::~Log(void) {
	;
}

void		Log::close(void) {
	Log::_log.close();
}

std::ofstream				&Log::getLog(void) {
	return (Log::_log);
}

void		Log::write(const std::string &msg) {
	Log::_log << msg << std::endl;
=======
	str = ft_strjoin(str, "\n");
	len = ft_strlen(str);
	send(sock, str, len, 0);
	free(str);
>>>>>>> 3fb45b870d19ae0d4347e66467354b39b6a86867:42/Zappy/client_dir/srcs/ft_send.c
}
