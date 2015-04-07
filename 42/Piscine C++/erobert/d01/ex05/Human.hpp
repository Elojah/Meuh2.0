// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 14:28:24 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 15:56:51 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include "Brain.hpp"

class Human
{
private:
	Brain const		_b;

public:
	Human(void);
	~Human(void);

	Brain const			&getBrain(void);

	std::string		identify(void);
};

#endif
