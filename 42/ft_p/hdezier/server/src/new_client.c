/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:23:45 by leeios            #+#    #+#             */
/*   Updated: 2016/04/20 17:12:25 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <stdlib.h>

static t_cmd	is_cmd(const char *s)
{
	static const char	*const cmds[] =
	{
		"ls",
		"cd",
		"get",
		"put",
		"pwd",
		"quit",
	};
	int			i;

	i = -1;
	if (s == NULL || s[0] == '\0' || s[0] == '\n')
		return (NONE);
	while (++i < NONE)
	{
		if (ft_strcmp(s, cmds[i]) == 0)
			return ((t_cmd)i);
	}
	return (NONE);
}

static t_bool		process_msg(int cs, t_client_data *client_data)
{
	char					*msg;
	char					**split_msg;
	t_cmd					cmd;

	write_log((char *)"Reading msg...", client_data);
	msg = read_data(cs);
	write_log((char *)"Received:", client_data);
	write_log(msg, client_data);
	if (msg == NULL)
	{
		write_log((char *)"Message bad format", client_data);
		return (TRUE);
	}
	split_msg = ft_strsplit(msg, ' ');
	free(msg);
	cmd = is_cmd(split_msg[0]);
	if (cmd == NONE)
		write_log((char *)"Command is not valid", client_data);
	exec_cmd(cmd, split_msg, client_data);
	ft_free_array_str(split_msg);
	return (cmd == QUIT ? FALSE : TRUE);
}

static void			goto_initial_dir(void)
{
	char	full_path[MAX_LEN_PATH + MAX_LEN_ROOT_PATH];

	getcwd(full_path, MAX_LEN_ROOT_PATH);
	ft_strcpy(full_path + ft_strlen(full_path), (char *)DEFAULT_PATH);
	if (chdir(full_path) == -1)
		ft_putstr("Can't access initial directory...\n");
}

void		new_client(int cs)
{
	t_client_data	client_data;

	init_log();
	client_data.cs = cs;
	ft_strcpy(client_data.current_path, (char *)"/");
	goto_initial_dir();
	write_log((char *)"Log initialization...", &client_data);
	while (process_msg(cs, &client_data) == TRUE)
		;
	close(cs);
	write_log((char *)"Client left", &client_data);
}
