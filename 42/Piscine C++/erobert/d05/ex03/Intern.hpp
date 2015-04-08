// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Intern.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 15:25:23 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 17:24:21 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"

class Intern
{
private:
	Intern(Intern const &i);

	Intern			&operator=(Intern const &i);
public:
	Intern(void);
	~Intern(void);

	Form			*makeForm(std::string const &fN, std::string const &t);
};

#endif
