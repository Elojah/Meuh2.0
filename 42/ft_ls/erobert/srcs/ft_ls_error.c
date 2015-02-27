/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 17:29:55 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 15:25:59 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_illegal(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putstr_fd(RED, 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd(END, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-GRSalrt] [file ...]", 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

int		ft_notopen(char *s)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(s, 0);
	ft_putstr_fd(END, 2);
	ft_putstr_fd(": No such file or directory or permission denied", 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

int		ft_nopermission(char *s)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(END, 2);
	ft_putstr_fd(": Permission denied", 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
