/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 18:55:19 by erobert           #+#    #+#             */
/*   Updated: 2015/02/25 13:57:20 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstrev(t_obj **obj)
{
	t_obj	*tmp1;
	t_obj	*tmp2;
	t_obj	*tmp3;

	if (!obj || !*obj)
		return ;
	tmp1 = *obj;
	tmp2 = 0;
	tmp3 = 0;
	while (tmp1)
	{
		tmp3 = tmp1->next;
		tmp1->next = tmp2;
		tmp2 = tmp1;
		tmp1 = tmp3;
	}
	*obj = tmp2;
}
