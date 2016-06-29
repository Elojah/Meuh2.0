/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 22:26:34 by shedelin          #+#    #+#             */
/*   Updated: 2015/03/06 22:26:36 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"
#include <libft.h>

void			ft_rec_print(unsigned long int nb)
{
	if (nb)
	{
		ft_rec_print(nb / 16);
		if ((nb % 16) < 10)
			ft_putchar((nb % 16) + '0');
		else
			ft_putchar((nb % 16) + 'A' - 10);
	}
}

void			ft_print_ptr(void *ptr)
{
	unsigned long int	nb;

	nb = 0;
	ft_putchar('0');
	ft_putchar('x');
	nb = (unsigned long int)ptr;
	ft_rec_print(nb);
}
