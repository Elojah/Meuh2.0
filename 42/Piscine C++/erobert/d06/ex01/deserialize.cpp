// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   deserialize.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 13:44:16 by erobert           #+#    #+#             //
//   Updated: 2015/01/13 15:19:50 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ex01.h"

Data		*deserialize(void *raw)
{
	t_s0	*seria;
	Data	*data = new Data();
	std::string	s("        ");
	int		i(-1);

	seria = static_cast<t_s0 *>(raw);
	while (++i < 8)
		s[i] = seria->s1[i];
	data->s1 = s;
	data->n = seria->n.n;
	i = -1;
	while (++i < 8)
		s[i] = seria->s2[i];
	data->s2 = seria->s2;
	return (data);
}
