/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 19:48:38 by leeios            #+#    #+#             */
/*   Updated: 2016/12/31 11:58:59 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memset(void *s, int c, int n)
{
	while (--n >= 0)
		*((char *)s + n) = c;
}

void	ft_free(void *p)
{
	if (p == NULL)
		return ;
	free(p);
	p = NULL;
}
