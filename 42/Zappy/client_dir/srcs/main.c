/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 17:07:39 by erobert           #+#    #+#             */
/*   Updated: 2014/06/27 10:46:32 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int						main(int ac, char **av)
{
	pondeur_init(ac, av, 1);
	while (1)
		pondeur_init(ac, av, 0);
	return (0);
}