/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchichep <jchichep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 12:30:19 by jchichep          #+#    #+#             */
/*   Updated: 2014/06/12 14:37:35 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"client.h"

void		new_client(int ac, char **av, int lvl)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (lvl == 0)
			pondeur_init(ac, av, 0);
		else
			lvl_1_init(ac, av);
	}
}
