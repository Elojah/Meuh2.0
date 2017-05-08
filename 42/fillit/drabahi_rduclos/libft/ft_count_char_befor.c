/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_befor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 11:24:00 by rduclos           #+#    #+#             */
/*   Updated: 2013/12/10 12:13:27 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_count_char_befor(char *str, char c)
{
	size_t		i;

	i = 0;
	while (str != NULL && str[i] != c && str[i] != '\0')
		i++;
	return (i);
}
