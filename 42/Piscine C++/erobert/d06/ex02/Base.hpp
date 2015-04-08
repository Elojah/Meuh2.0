// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Base.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 15:36:51 by erobert           #+#    #+#             //
//   Updated: 2015/01/13 15:38:49 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef
# define

class Base
{
private:
	Base(void);
	Base(Base const &b);

	Base		&operator=(Base const &b);
public:
	virtual ~Base(void);
}

#endif
