/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tryint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:27:18 by rduclos           #+#    #+#             */
/*   Updated: 2017/02/20 17:15:24 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ti(int ret, int err, char *where)
{
	if (ret == err)
		ft_die(error(ret, strerror(errno)), where);
	return (ret);
}
