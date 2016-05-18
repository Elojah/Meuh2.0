/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 13:06:03 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 13:37:11 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	ft_print_success(char *s1, char *s2)
{
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("SUCCESS", 2);
	ft_putstr_fd(END, 1);
	ft_putstr_fd(s1, 1);
	ft_putendl_fd(s2, 1);
}

static void	ft_print_error(char *s1, char *s2)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd("ERROR", 2);
	ft_putstr_fd(END, 1);
	ft_putstr_fd(s1, 1);
	ft_putendl_fd(s2, 1);
}

int			ft_print_result(char *s1, char *s2, int res)
{
	if (res < 0)
	{
		ft_print_error(s1, s2);
		return (res);
	}
	else
	{
		ft_print_success(s1, s2);
		return (res);
	}
}
