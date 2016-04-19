/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:08:03 by leeios            #+#    #+#             */
/*   Updated: 2016/04/19 20:06:50 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

#include <unistd.h>

static t_bool	add_to_path(char *param, t_client_data *client_data)
{
	int		len_orig_path;
	int		len_final_path;

	len_orig_path = ft_strlen(client_data->current_path);
	len_final_path = ft_strlen(param);
	if (len_orig_path + len_final_path >= MAX_LEN_PATH)
		return (FALSE);
	ft_strcpy(client_data->current_path + len_orig_path, param);
	client_data->current_path[len_orig_path + len_final_path] = '/';
	return (TRUE);
}

static t_bool	add_to_root(t_client_data *client_data)
{
	char	full_path[MAX_LEN_PATH + MAX_LEN_ROOT_PATH];

	getcwd(full_path, MAX_LEN_ROOT_PATH);
	ft_strcpy(full_path + ft_strlen(full_path), client_data->current_path);
	if (chdir(full_path) == -1)
	{
		write(client_data->cs, "Can't access this directory\n", 28);
		return (FALSE);
	}
	return (TRUE);
}

t_bool			builtin_cd(char *param, t_client_data *client_data)
{
	char	save_path[MAX_LEN_PATH];

	if (param == NULL || param[0] == '\0')
	{
		ft_strcpy(client_data->current_path, (char *)"/data/");
		SUCCESS;
		return (TRUE);
	}
	else
	{
		ft_strcpy(save_path, client_data->current_path);
		if (add_to_path(param, client_data) == FALSE)
			goto error;
		if (add_to_root(client_data) == FALSE)
		{
			ft_strcpy(client_data->current_path, save_path);
			goto error;
		}
		SUCCESS;
		return (TRUE);
	}
	error :
	write(client_data->cs, "ERROR\nAccess denied\0", 20);
	return (FALSE);
}
