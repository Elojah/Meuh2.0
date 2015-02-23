/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 15:23:01 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 13:20:58 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <termcap.h>
#include <curses.h>
#include <termios.h>
#include "ft_minishell1.h"

static void				ft_noncanonical(t_termios *oldline)
{
	static t_termios	line;

	if (tcgetattr(0, oldline) < 0)
		ft_putstr_fd("Error: tcgetattr", 2);
	ft_memmove(&line, oldline, sizeof(line));
	line.c_lflag &= ~(ICANON | ECHO);
	line.c_cc[VMIN] = 1;
	line.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &line) < 0)
		ft_putstr_fd("Error: tcsetattr", 2);
}

static void				ft_restore(t_termios *oldline)
{
	if (tcsetattr(0, TCSANOW, oldline) < 0)
		ft_putstr_fd("Error: tcsetattr", 2);
}

void					ft_mode(int mode)
{
	static t_termios	oldline;

	if (mode)
		ft_noncanonical(&oldline);
	else
		ft_restore(&oldline);
}
