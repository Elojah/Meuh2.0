/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 15:08:27 by rduclos           #+#    #+#             */
/*   Updated: 2015/01/20 17:46:12 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_putpnbr(unsigned int n)
{
	unsigned int	div;
	unsigned int	index;

	index = 0;
	div = 1;
	while ((n / div) >= 10)
		div = div * 10;
	while (div > 0)
	{
		index += ft_putchar((n / div) % 10 + 48);
		div = div / 10;
	}
	return (index);
}
