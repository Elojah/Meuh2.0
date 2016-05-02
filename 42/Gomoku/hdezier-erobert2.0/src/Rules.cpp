/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rules.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:55:29 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 00:18:59 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rules.h"

bool		Rules::isValid(const IBoard &board, const common::vec2 &stroke)
{
	(void)board;
	(void)stroke;
	return (true);
}

common::eCell	Rules::gameEnded(const IBoard &board, const common::eCell &turn)
{
	(void)board;
	(void)turn;
	return (common::eCell::E_CELL);
}
