// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IOperand.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/23 16:24:18 by erobert           #+#    #+#             //
//   Updated: 2015/01/24 05:03:36 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef I_OPERAND_HPP
# define I_OPERAND_HPP

# include <string>
# include "avm.h"

class IOperand
{
public:
	virtual ~IOperand(void) {}

	virtual IOperand const		*operator+(IOperand const &rhs) const = 0;
	virtual IOperand const		*operator-(IOperand const &rhs) const = 0;
	virtual IOperand const		*operator*(IOperand const &rhs) const = 0;
	virtual IOperand const		*operator/(IOperand const &rhs) const = 0;
	virtual IOperand const		*operator%(IOperand const &rhs) const = 0;

	virtual int					getPrecision(void) const = 0;
	virtual eOperandType		getType(void) const = 0;

	virtual std::string const	&toString(void) const = 0;
};

#endif
