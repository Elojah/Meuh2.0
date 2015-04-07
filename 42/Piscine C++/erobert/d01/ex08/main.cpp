// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 18:53:16 by erobert           #+#    #+#             //
//   Updated: 2015/01/06 20:14:30 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

int			main(void)
{
	Human	h;

	h.action("meleeAttack", "Clinton");
	h.action("rangedAttack", "Bush");
	h.action("intimidatingShout", "Obama");
}
