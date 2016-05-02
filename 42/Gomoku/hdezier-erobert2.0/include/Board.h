/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:47:10 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/02 23:04:51 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

# include "stdint.h"
# include "common.h"
# include "Rules.h"
# include <cstring>

class IBoard
{
public:
	virtual ~IBoard(void) {};
	virtual void			setCell(const common::vec2 &stroke, const common::eCell &player) = 0;
	virtual common::eCell	getCell(const common::vec2 &coord) = 0;
};

template <uint8_t N>
class	Board : public IBoard
{
public:
	inline Board(void) {std::memset(m_board, (int)common::eCell::NONE, sizeof(m_board));};

	inline Board(const IBoard &copy) {(void)copy;};

	inline virtual ~Board(void) {};

	inline virtual void				setCell(const common::vec2 &stroke, const common::eCell &player) {m_board[stroke.x][stroke.y] = player;};
	inline virtual common::eCell	getCell(const common::vec2 &coord) {return (m_board[coord.x][coord.y]);};
private:
	common::eCell			m_board[N][N];
};

#endif
