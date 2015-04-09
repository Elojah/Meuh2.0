// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISpaceObject.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 09:29:05 by erobert           #+#    #+#             //
//   Updated: 2015/01/11 15:44:31 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_SPACE_OBJECT_HPP
# define I_SPACE_OBJECT_HPP

# include "ft_retro.h"

class ISpaceObject
{
public:
	virtual ~ISpaceObject(void) {}

	virtual void	retriveSpaceObject(t_spaceObject &sO) const = 0;
};

#endif
