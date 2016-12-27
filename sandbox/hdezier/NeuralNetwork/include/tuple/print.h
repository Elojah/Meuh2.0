/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 11:57:12 by leeios            #+#    #+#             */
/*   Updated: 2016/12/27 13:25:49 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_PRINT_H
# define TUPLE_PRINT_H

# include "tuple/for_each.h"
# include <iostream>

namespace tuple
{

// TODO print_tuple rec with
// is_specialization_of<Type, std::tuple>::value
	template<typename Tuple>
	static inline void		print(Tuple const &&t)
	{
		for_each([](auto &&v)
		{
				std::cout << v << ',';
		}, std::move(t));
		std::cout << std::endl;
	}
};

#endif
