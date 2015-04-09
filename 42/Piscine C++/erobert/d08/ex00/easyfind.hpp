// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   easyfind.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 09:55:17 by erobert           #+#    #+#             //
//   Updated: 2015/01/15 14:44:58 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <algorithm>
# include <iostream>

template<typename T>
int								easyfind(T const &t, int const i)
{
	typename T::const_iterator	it(0);
	
	it = find(t.begin(), t.end(), i);
	if (it != t.end())
		return (std::distance(t.begin(), it));
	else
		return (-1);
}

#endif
