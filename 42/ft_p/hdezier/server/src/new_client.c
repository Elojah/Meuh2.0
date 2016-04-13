/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:23:45 by leeios            #+#    #+#             */
/*   Updated: 2016/04/13 21:48:57 by leeios           ###   ########.fr       */
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
	char	*msg;
	char	size_data[10];
	int		i;
	int		r;

	i = -1;
	r = 1;
	while (++i < 9 && r > 0)
	{
		r = read(cs, &(size_data[i]), 1);
		ft_putchar(size_data[i]);
		if (size_data[i] == '.')
		{
			size_data[i + 1] = '\0';
			i = ft_atoi(size_data);
			msg = (char *)ft_memalloc(i);
			r = read(cs, msg, i);
			msg[r] = '\0';
			write_log(msg, NULL);
			return (msg);
		}
		else if (size_data[i] < '0' || size_data[i] > '9')
			return (NULL);
	}
	return (NULL);
}

static t_bool		process_msg(int cs, t_client_data *client_data)
{
	char					*msg;
	char					**split_msg;
	t_cmd					cmd;

	write_log((char *)"Reading msg...\n", NULL);
	msg = read_socket(cs);
	if (msg == NULL)
	{
		write_log((char *)"Message bad format\n", client_data);
		return (TRUE);
	}
	split_msg = ft_strsplit(msg, ' ');
	free(msg);
	cmd = is_cmd(split_msg[0]);
	if (cmd == NONE)
		write_log((char *)"Command is not valid\n", client_data);
	exec_cmd(cmd, split_msg, client_data);
	ft_free_array_str(split_msg);
	return (cmd == QUIT ? FALSE : TRUE);
}

void		new_client(int cs)
{
	t_client_data	client_data;

	init_log();
	client_data.cs = cs;
	ft_strcpy(client_data.current_path, (char *)"./data");
	write_log((char *)"Log initialization...\n", &client_data);
	process_msg(cs, &client_data);
	while (process_msg(cs, &client_data) == TRUE)
		;
	close(cs);
}
