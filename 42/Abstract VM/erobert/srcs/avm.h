/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 05:01:11 by erobert           #+#    #+#             */
/*   Updated: 2015/01/28 17:52:34 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVM_H
# define AVM_H

# include <string>

enum				eOperandType
{
	INT8 = 0,
	INT16,
	INT32,
	FLOAT,
	DOUBLE,
	NONE
};
enum				eInstruction
{
	POP = 0,
	DUMP,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	PRINT,
	EXIT,
	PUSH,
	ASSERT
};

struct				sCommand
{
	eOperandType	op;
	eInstruction	instr;
	std::string		val;
};

#endif
