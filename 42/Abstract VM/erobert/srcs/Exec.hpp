// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Exec.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 10:21:05 by erobert           #+#    #+#             //
//   Updated: 2015/02/06 16:51:07 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EXEC_HPP
# define EXEC_HPP

# include <iostream>
# include <list>
# include <string>
# include "IOperand.hpp"
# include "FOperand.hpp"
# include "avm.h"

class Exec
{
private:
	std::list<IOperand const *>	_cmd;
	FOperand					_fO;

	Exec(Exec const &e);

	Exec						&operator=(Exec const &e);

	void						push(eOperandType type,
									 std::string const &value);
	void						pop(void);
	void						dump(void);
	void						assert(eOperandType type,
									   std::string const &value);
	void						doOp(eInstruction instr);
	void						print(void);
	void						exit(void);
public:
	Exec(void);
	~Exec(void);

	void						execCommand(std::list<sCommand> cmd);

	class BadStack: public std::exception
	{
	private:
		BadStack				&operator=(BadStack const &bS);
	public:
		BadStack(void);
		BadStack(BadStack const &bS);
		virtual ~BadStack(void) throw();

		virtual char const		*what(void) const throw();
	};
	class BadAssert: public std::exception
	{
	private:
		BadAssert				&operator=(BadAssert const &bA);
	public:
		BadAssert(void);
		BadAssert(BadAssert const &bA);
		virtual ~BadAssert(void) throw();

		virtual char const		*what(void) const throw();
	};
	class BadPrint: public std::exception
	{
	private:
		BadPrint				&operator=(BadPrint const &bP);
	public:
		BadPrint(void);
		BadPrint(BadPrint const &bP);
		virtual ~BadPrint(void) throw();

		virtual char const		*what(void) const throw();
	};
};

#endif
