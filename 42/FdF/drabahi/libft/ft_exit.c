/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:06:23 by drabahi           #+#    #+#             */
/*   Updated: 2015/01/23 00:06:29 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_exit(int test, char *err_msg)
{
	if (!test)
		return ;
	else
	{
		ft_putendl_fd(err_msg, 2);
		exit(1);
	}
}
