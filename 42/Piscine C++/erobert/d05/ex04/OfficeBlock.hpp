// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OfficeBlock.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 17:33:02 by erobert           #+#    #+#             //
//   Updated: 2015/01/12 18:06:48 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OFFICE_BLOCK_HPP
# define OffICE_BLOCK_HPP

# include "Bureaucrat.hpp"
# include "Intern.hpp"

class OfficeBlock
{
private:
	Bureaucrat			*_sB;
	Bureaucrat			*_eB;
	Intern				*_i;

	OfficeBlock(OfficeBlock const &oB);

	OfficeBlock		&operator=(OfficeBlock const &oB);
public:
	OfficeBlock(void);
	OfficeBlock(Bureaucrat *sB, Bureaucrat *eB, Intern *i);
	~OfficeBlock(void);

	void			setSigner(Bureaucrat *b);
	void			setExecutor(Bureaucrat *b);
	void			setIntern(Intern *i);

	void			doBureaucracy(std::string const &fN, std::string const &tN);
};

#endif
