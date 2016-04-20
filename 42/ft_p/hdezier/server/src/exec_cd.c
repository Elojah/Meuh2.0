/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:08:03 by leeios            #+#    #+#             */
/*   Updated: 2016/04/20 19:44:49 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

#include <unistd.h>

static void		resolve_path(char *path)
{
	int			i;
	int			prev;

	i = -1;
	while (path[++i] != '\0')
	{
		if (ft_strncmp(path + i, "/..", 3) == 0)
		{
			prev = i;
			while (--prev >= 0)
			{
				if (prev != '/')
					continue ;
				ft_strcpy(path + prev, path + i + 3);
				i = prev;
			}
		}
	}
}

static t_bool	add_to_path(char *param, t_client_data *client_data
	, t_ret_msg *msg)
{
	int		len_orig_path;
	int		len_final_path;

	len_orig_path = ft_strlen(client_data->current_path);
	len_final_path = ft_strlen(param);
	if (len_orig_path + len_final_path >= MAX_LEN_PATH)
	{
		append_msg(msg, (char *)"Path too long\n");
		return (FALSE);
	}
	ft_strcpy(client_data->current_path + len_orig_path, param);
	client_data->current_path[len_orig_path + len_final_path] = '/';
	return (TRUE);
}

static t_bool	add_to_root(t_client_data *client_data, t_ret_msg *msg)
{
	char	full_path[MAX_LEN_PATH + MAX_LEN_ROOT_PATH];

	getcwd(full_path, MAX_LEN_ROOT_PATH);
	ft_strcpy(full_path + ft_strlen(full_path), client_data->current_path);
	resolve_path(full_path);
	if (chdir(full_path) == -1)
	{
		append_msg(msg, (char *)"Can't access this directory\n");
		append_msg(msg, full_path);
		append_msg(msg, (char *)"\n");
		return (FALSE);
	}
	return (TRUE);
}

void			exec_cd(char **param, t_client_data *client_data, t_ret_msg *msg)
{
	char	save_path[MAX_LEN_PATH];

	if (param == NULL || param[1] == NULL)
	{
		ft_strcpy(client_data->current_path, (char *)"/");
		msg->ret = SUCCESS;
	}
	else
	{
		ft_strcpy(save_path, client_data->current_path);
		if (add_to_path(param[1], client_data, msg) == FALSE)
			msg->ret = ERROR;
		else if (add_to_root(client_data, msg) == FALSE)
		{
			ft_strcpy(client_data->current_path, save_path);
			msg->ret = ERROR;
		}
		else
			msg->ret = SUCCESS;
	}
}
