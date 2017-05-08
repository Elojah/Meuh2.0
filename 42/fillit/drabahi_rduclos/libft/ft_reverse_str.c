/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:25:15 by rduclos           #+#    #+#             */
/*   Updated: 2015/03/01 18:45:22 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_str(char *str)
{
	size_t	i;
	size_t	j;
	char	*reverse;

	i = 0;
	j = ft_strlen(str) - 1;
	reverse = (char *)malloc(sizeof(char) * (j + 2));
	while (i < ft_strlen(str))
	{
		reverse[i] = str[j];
		i++;
		j--;
	}
	reverse[i] = '\0';
	free(str);
	return (reverse);
}
