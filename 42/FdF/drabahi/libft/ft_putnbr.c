/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 00:05:11 by drabahi           #+#    #+#             */
/*   Updated: 2015/01/23 00:05:11 by drabahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	quo;
	int	mod;

	if (n > 9)
	{
		quo = n / 10;
		ft_putnbr(quo);
		mod = n % 10;
		ft_putchar(mod + '0');
	}
	else if ((n > -1) && (n < 10))
		ft_putchar(n + '0');
	else if (n < -2147483647)
		ft_putstr("-2147483648");
	else
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
}
