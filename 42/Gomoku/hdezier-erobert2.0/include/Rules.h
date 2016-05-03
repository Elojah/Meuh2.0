/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:33 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 02:36:48 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "common.h"

class IBoard;

class Rules
{
public:

	Rules(void) = default;
	virtual ~Rules(void) = default;

	static bool				isValid(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn);
	static common::eCell	gameEnded(const IBoard &board, const common::vec2 &stroke);

private:
	static bool				_insertDoubleFreeThree(const IBoard &board, const common::vec2 &stroke, const common::eCell &turn);
};

#endif
