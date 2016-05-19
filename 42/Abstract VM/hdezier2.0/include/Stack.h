/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 15:30:16 by leeios            #+#    #+#             */
/*   Updated: 2016/05/19 13:00:22 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "Tokens.h"
# include <vector>

class Stack
{
public:

	enum class	eResult
	{
		OK,
		DIV_BY_ZERO,
		NOT_ENOUGH_VALUES,
		ASSERT_FALSE
	};

	Stack(void) = default;
	~Stack(void) = default;

	eResult		doOperation(const lexOperations::sPush &param);
	eResult		doOperation(const lexOperations::sPop &param);

	eResult		doOperation(const lexOperations::sPrint &param) const;
	eResult		doOperation(const lexOperations::sAssert &param) const;
	eResult		doOperation(const lexOperations::sDump &param) const;

	eResult		doOperation(const lexOperations::sAdd &param);
	eResult		doOperation(const lexOperations::sSub &param);
	eResult		doOperation(const lexOperations::sMul &param);
	eResult		doOperation(const lexOperations::sDiv &param);
	eResult		doOperation(const lexOperations::sMod &param);

private:

	std::vector<const IOperand *>		m_container;
};

#endif
