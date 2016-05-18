/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:52:46 by leeios            #+#    #+#             */
/*   Updated: 2016/05/17 18:23:45 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

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
	QUIT,
	ERR,
	NONE,
	E_TOKEN
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
