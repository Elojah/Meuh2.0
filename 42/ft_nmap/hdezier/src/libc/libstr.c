/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:02:59 by leeios            #+#    #+#             */
/*   Updated: 2016/12/31 12:00:02 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"
#include <stdlib.h>

int		ft_strcmp(const char *lhs,const char *rhs)
{
	if (lhs == NULL || rhs == NULL)
		return (-1);
	while (*lhs == *rhs && *lhs != '\0' && *rhs != '\0')
	{
		++lhs;
		++rhs;
	}
	return (*lhs - *rhs);
}

int		ft_strncmp(const char *lhs,const char *rhs, int n)
{
	if (lhs == NULL || rhs == NULL)
		return (-1);
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

int			ft_uatoi(char **s)
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


/*
* This is parsing !
*/
char		*get_next_token(char **s, char c)
{
	char		*token;

	token = *s;
	if (**s == '\0')
		return (NULL);
	while (**s != '\0' && **s != c)
		++*s;
	if (**s == c)
	{
		**s = '\0';
		++*s;
	}
	return (token);
}
