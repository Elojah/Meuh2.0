/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:41:44 by leeios            #+#    #+#             */
/*   Updated: 2016/04/20 00:36:27 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>

typedef enum		e_bool
{
	FALSE = 0,
	TRUE
}					t_bool;

void		connect_ftp(char *addr, int port);
void		read_prompt(int sock);
void		send_file(char *s, int sock);

#endif
