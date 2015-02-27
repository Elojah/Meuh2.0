/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 19:06:28 by drabahi           #+#    #+#             */
/*   Updated: 2015/02/22 19:06:28 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		main(void)
{
	test_ft_bzero();
	test_ft_isstuff(&ft_isalpha, &isalpha);
	test_ft_isstuff(&ft_isdigit, &isdigit);
	test_ft_isstuff(&ft_isalnum, &isalnum);
	test_ft_isstuff(&ft_isascii, &isascii);
	test_ft_isstuff(&ft_isprint, &isprint);
	test_ft_tostuff(&ft_toupper, &toupper);
	test_ft_tostuff(&ft_tolower, &tolower);
	test_ft_isstuff(&ft_isupper, &isupper);
	test_ft_isstuff(&ft_islower, &islower);
	test_ft_putchar();
	test_ft_puts();
	test_ft_putstr();
	test_ft_swap();
	test_ft_strlen();
	test_ft_strcat();
	test_ft_memset();
	test_ft_memcpy();
	test_ft_strdup();
	test_ft_cat();
	return (0);
}
