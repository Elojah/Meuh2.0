// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CentralBureaucracy.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 18:27:37 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 18:30:08 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CENTRAL_BUREAUCRACY_HPP
#define CENTRAL_BUREAUCRACY_HPP

#incldue "OfficeBlock.hpp"

class CentralBureaucracy
{
private:
	OfficeBlock					_oBs[20];

	CentralBureaucracy(void);
	CentralBureaucracy(CentralBureaucracy const &cB);

	CentralBureaucracy			&operator=(CentralBureaucracy const &cB);
public:
	~CentralBureaucracy(void);
}

#endif
