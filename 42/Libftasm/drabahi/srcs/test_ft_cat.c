/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_cat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_ft_cat(void)
{
	int		fd;

	if ((fd = open("Makefile", O_RDONLY)) < 0)
	{
		printf("Open foire");
		return ;
	}
	printf("== %s ==\n", __func__);
	printf("Cat Erreur \n");
	ft_cat(-42);

	// printf("Cat 0 \n");
	// ft_cat(0);

	// printf("Cat fd \n");
	// ft_cat(fd);

	close(fd);
	return ;
}
