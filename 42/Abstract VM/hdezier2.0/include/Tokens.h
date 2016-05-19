/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:52:46 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 19:04:56 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define DBG_MSG(n) std::cout << (n) << std::endl;

# include "IOperand.h"
# include <string>

enum class	eToken
{
	PUSH,
	POP,
	PRINT,
	ASSERT,
	DUMP,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	EXIT,
	ERR,
	NONE,
	E_TOKEN
};

enum class	eErr
{
	NONE = 0,
	EXIT,
	SYNTAX_ERROR,
	UNKNOWN_INSTR,
	OVERFLOW,
	UNDERFLOW,
	POP_ON_EMPTY_STACK,
	DIV_BY_ZERO,
	MISSING_OPERANDS,
	NO_EXIT_INSTR,
	ASSERT_FALSE
};

namespace lexOperations
{
	struct	sElem
	{
		IOperand::eOperandType	type;
		std::string				elem;
	};
	struct	sPush : sElem
	{
	};
	struct	sAssert : sElem
	{
	};

	struct	sPrint {};

	struct	sPop {};
	struct	sDump {};

	struct	sAdd {};
	struct	sSub {};
	struct	sMul {};
	struct	sDiv {};
	struct	sMod {};
};

#endif
