/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 11:25:40 by rduclos           #+#    #+#             */
/*   Updated: 2015/01/20 17:47:32 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_str(char *str, size_t n)
{
	char	*tmp;

	if (str)
	{
		tmp = ft_strdup(str);
		str = (char *)malloc(sizeof(char) * n + 1);
		free(str);
		str = NULL;
		str = (char *)malloc(sizeof(char) * n + 1);
		str = ft_strcpy(str, tmp);
		free(tmp);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * n + 1);
	}
	return (str);
}
