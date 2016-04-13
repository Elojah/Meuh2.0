/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:52:30 by leeios            #+#    #+#             */
/*   Updated: 2016/04/13 17:19:02 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "client.h"
#include "libft.h"

static char		*read_user(void)
{
	char	*buf;
	int		r;

	buf = (char *)ft_memalloc((BUFF_SIZE + 1) * sizeof(char));
	r = read(0, buf, BUFF_SIZE);
	buf[r] = '\0';
	return (buf);
}

void		read_prompt(int sock)
{
	char	*s;

	while (1)
	{
		ft_putstr("$>");
		s = read_user();
		write(sock, s, BUFF_SIZE);
		read(sock, s, BUFF_SIZE);
		ft_putstr(s);
		free(s);
	}
}
