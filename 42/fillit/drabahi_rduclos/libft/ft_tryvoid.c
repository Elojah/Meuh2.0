/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tryvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:27:18 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:15:44 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_tv(void *ret, void *err, char *where)
{
	if (ret == err)
		ft_die(error(1, strerror(errno)), where);
	return (ret);
}
