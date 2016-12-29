/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:02:59 by leeios            #+#    #+#             */
/*   Updated: 2016/12/29 21:17:43 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

int		ft_strcmp(const char *lhs,const char *rhs)
{
	while (*lhs == *rhs && *lhs != '\0' && *rhs != '\0')
	{
		++lhs;
		++rhs;
	}
	return (*lhs - *rhs);
}

int		ft_strncmp(const char *lhs,const char *rhs, int n)
{
	if (n == 0)
		return (0);
	while (--n > 0 && *lhs == *rhs && *lhs != '\0' && *rhs != '\0')
	{
		++lhs;
		++rhs;
	}
	return (*lhs - *rhs);
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_uatoi(char **s)
{
	int	result;

	result = 0;
	while (is_digit(**s))
	{
		result *= 10;
		result += **s - '0';
		++*s;
	}
	return (result);
}
