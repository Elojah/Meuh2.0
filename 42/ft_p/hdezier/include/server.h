/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:22:55 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/11 16:33:26 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

enum				e_bool
{
	FALSE = 0,
	TRUE
};

enum				e_cmd
{
	LS = 0,
	CD,
	GET,
	PUT,
	PWD,
	QUIT,
	NONE
};

void			listen_port(int port);
void			exec_cmd(e_cmd cmd, char **msg);


#endif
