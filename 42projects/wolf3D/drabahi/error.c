/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 22:35:46 by drabahi           #+#    #+#             */
/*   Updated: 2014/01/19 23:13:16 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int	no_map()
{
	ft_putendl("Error map");
	exit(0);
	return (0);
}

int	no_rec()
{
	ft_putendl("map no rectangular");
	return (0);
}

int	all_many_ar()
{
	ft_putendl("To many arguments");
	return (0);
}

