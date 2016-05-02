/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:33 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 00:27:15 by hdezier          ###   ########.fr       */
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

	static bool				isValid(const IBoard &board, const common::vec2 &stroke);
	static common::eCell	gameEnded(const IBoard &board, const common::eCell &turn);
};

#endif
