/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:50:32 by rduclos           #+#    #+#             */
/*   Updated: 2015/01/20 17:48:19 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		index;
	int		len;

	index = 0;
	len = ft_strlen(s1);
	while (s2 && s2[index] != '\0')
	{
		s1[len] = s2[index];
		len++;
		index++;
	}
	s1[len] = '\0';
	return (s1);
}
