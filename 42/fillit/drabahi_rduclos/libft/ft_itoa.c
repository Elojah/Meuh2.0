/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:12:40 by tmielcza          #+#    #+#             */
/*   Updated: 2015/06/10 19:59:43 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_itoa(long long int n)
{
	long long int	n2;
	int				z;
	char			*mem;

	n2 = n;
	z = 0;
	while (n2 > 9 || n2 < (-9))
	{
		n2 /= 10;
		z++;
	}
	n2 = n < 0 ? 1 : 0;
	if ((mem = ft_strnew(z * sizeof(char) + n2 + 1)))
	{
		mem[0] = n < 0 ? '-' : mem[0];
		while (z >= 0)
		{
			mem[n2 + z--] = '0' + FT_ABS(n % 10);
			n /= 10;
		}
	}
	return (mem);
}
