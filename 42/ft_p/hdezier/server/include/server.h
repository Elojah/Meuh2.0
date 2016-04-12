/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:22:55 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/12 19:41:52 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define MAX_CLIENT 1024
# define MAX_LEN_PATH 1024
# define DEFAULT_PATH "."

# include <unistd.h>

typedef void	(*t_cmd_ft)(char **);

typedef struct		s_client_data
{
	int				id;
	pid_t			child;
	char			current_path[MAX_LEN_PATH];
}					t_client_data;

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
e_bool			init_client(pid_t child);


#endif
