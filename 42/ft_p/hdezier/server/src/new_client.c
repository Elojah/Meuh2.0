/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:23:45 by leeios            #+#    #+#             */
/*   Updated: 2016/04/13 17:23:05 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include <stdlib.h>

static t_cmd	is_cmd(char *s)
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
	while (++i < NONE)
	{
		if (ft_strcmp(s, cmds[i]) == 0)
			return ((t_cmd)i);
	}
	return (NONE);
}

static char		*read_socket(int cs)
{
	char	*buf;
	int		r;

	buf = (char *)ft_memalloc((BUFF_SIZE + 1) * sizeof(char));
	r = read(cs, buf, BUFF_SIZE);
	buf[r] = '\0';
	return (buf);
}

static t_bool		process_msg(int cs, t_client_data *client_data)
{
	char					*msg;
	char					**split_msg;
	t_cmd					cmd;

	msg = read_socket(cs);
	if (msg == NULL)
		return (TRUE);
	split_msg = ft_strsplit(msg, ' ');
	free(msg);
	cmd = is_cmd(split_msg[0]);
	if (cmd == NONE)
		ft_putstr_fd("Command is not valid\n", cs);
	exec_cmd(cmd, split_msg, client_data);
	ft_free_array_str(split_msg);
	return (cmd == QUIT ? FALSE : TRUE);
}

void		new_client(int cs)
{
	t_client_data	client_data;

	client_data.cs = cs;
	ft_strcpy((char *)"./data", client_data.current_path);
	while (process_msg(cs, &client_data) == TRUE)
		;
	close(cs);
}
