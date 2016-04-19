/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:22:55 by hdezier           #+#    #+#             */
/*   Updated: 2016/04/19 19:59:46 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define MAX_CLIENT 1024
# define MAX_LEN_PATH 1024
# define MAX_LEN_ROOT_PATH 1024
# define DEFAULT_PATH "."

# define SUCCESS write(client_data->cs, "SUCCESS\0", 8)

# include <unistd.h>

typedef struct		s_client_data
{
	int				cs;
	char			current_path[MAX_LEN_PATH];
}					t_client_data;

typedef void	(*t_cmd_ft)(char **, t_client_data*);

typedef enum		e_bool
{
	FALSE = 0,
	TRUE
}					t_bool;

typedef enum		e_cmd
{
	LS = 0,
	CD,
	GET,
	PUT,
	PWD,
	QUIT,
	NONE
}					t_cmd;


void			listen_port(int port);
void			new_client(int cs);
void			exec_cmd(t_cmd cmd, char **msg, t_client_data *client_data);

/*
**BUILTINS
*/
t_bool			builtin_cd(char *param, t_client_data *client_data);

/*
** LOG
*/
void		init_log(void);
void		write_log(char *s, const t_client_data *client_data);

#endif
