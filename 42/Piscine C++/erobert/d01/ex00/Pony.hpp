// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 09:10:38 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 09:47:19 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONY_H
# define PONY_H

class Pony
{
private:
	bool	_bad;

public:
	Pony(bool bad);
	~Pony(void);
	
	bool	jumpStupid(void);
};

#endif
