// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IObject.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/06 16:08:34 by erobert           #+#    #+#             //
//   Updated: 2015/02/06 16:10:26 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_OBJECT_HPP
# define I_OBJECT_HPP

class IObject
{
public:
	virtual ~IObject(void) {}

	virtual void	drawObject(void) = 0;
};

#endif
