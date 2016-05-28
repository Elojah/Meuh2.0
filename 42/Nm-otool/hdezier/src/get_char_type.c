/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:32:24 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/28 17:41:10 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <mach-o/nlist.h>

char		get_char_type(uint8_t type)
{
	if (type == N_UNDF)
		type = 'U';
	else if (type == N_ABS)
		type = 'A';
	else if (type == N_SECT)
		type = 'T';
	else if (type == N_PBUD)
		type = 'D';
	else if (type == N_INDR)
		type = 'I';

	(void)type;
	return ('N');
}
