/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:47:10 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 00:29:43 by hdezier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

# include "stdint.h"
# include "common.h"
# include "Rules.h"
# include <cstring>
# include <unistd.h>

class IBoard
{
public:
	virtual ~IBoard(void) {};
	virtual void			setCell(const common::vec2 &stroke, const common::eCell &player) = 0;
	virtual common::eCell	getCell(const common::vec2 &coord) const = 0;
};

template <uint8_t N>
class	Board : public IBoard
{

public:
	inline Board(void) {reset();};

	inline Board(const IBoard &copy) {(void)copy;};

	inline virtual ~Board(void) {};

	inline virtual void				setCell(const common::vec2 &stroke, const common::eCell &player)
	{
		if (isValid(stroke))
			m_board[stroke.x][stroke.y] = player;
	};
	inline virtual common::eCell	getCell(const common::vec2 &coord) const
	{
		if (isValid(coord))
			return (m_board[coord.x][coord.y]);
		else
			return (common::eCell::E_CELL);
	};
	inline virtual void				reset(void) {std::memset(m_board, (int)common::eCell::NONE, sizeof(m_board));};

	inline virtual void				displayBoard(void) const
	{
		for (uint8_t i = 0; i < N; ++i)
		{
			for (uint8_t j = 0; j < N; ++j)
			{
				char	c;
				if (m_board[i][j] == common::eCell::P1)
					c = '1';
				else if (m_board[i][j] == common::eCell::P2)
					c = '2';
				else if (m_board[i][j] == common::eCell::NONE)
					c = '_';
				write(1, &c, 1);
			}
			write(1, "\n", 1);
		}
	};


private:
	common::eCell			m_board[N][N];

	static inline bool		isValid(const common::vec2 &stroke) {return (stroke.x >= 0 && stroke.x < N && stroke.y >= 0 && stroke.y < N);};
};

#endif
