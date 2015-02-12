// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FOperand.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 10:44:23 by erobert           #+#    #+#             //
//   Updated: 2015/01/28 15:02:39 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef F_OPERAND_HPP
# define F_OPERAND_HPP

# include "IOperand.hpp"
# include "avm.h"

class FOperand
{
private:
	typedef IOperand const	*(FOperand::*create)(std::string const &) const;

	create					_function[5];

	FOperand(FOperand const &fO);

	FOperand				&operator=(FOperand const &fO);

	IOperand const			*createInt8(std::string const &value) const;
	IOperand const			*createInt16(std::string const &value) const;
	IOperand const			*createInt32(std::string const &value) const;
	IOperand const			*createFloat(std::string const &value) const;
	IOperand const			*createDouble(std::string const &value) const;
public:
	FOperand(void);
	~FOperand(void);

	IOperand const			*createOperand(eOperandType type,
										   std::string const &value) const;
};

#endif
