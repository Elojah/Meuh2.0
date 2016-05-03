/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 20:47:10 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/03 03:56:01 by hdezier          ###   ########.fr       */
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
	virtual common::eCell	getCell(const common::vec2 &origin, common::eDirection dir, uint8_t dist) const = 0;
	virtual int8_t			countAlign(const common::vec2 &stroke, common::eDirection dir, common::eCell player) const = 0;
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
		if (_isValid(stroke))
			m_board[stroke.x][stroke.y] = player;
	};
	inline virtual common::eCell	getCell(const common::vec2 &coord) const
	{
		if (_isValid(coord))
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
	inline virtual common::eCell	getCell(const common::vec2 &origin, common::eDirection dir, uint8_t dist) const
	{
		common::vec2		dest;

		dest.x = origin.x;
		dest.y = origin.y;
		switch (dir)
		{
			case (common::eDirection::U) :
				dest.y -= dist;
				break ;
			case (common::eDirection::UR) :
				dest.y -= dist;
				dest.x += dist;
				break ;
			case (common::eDirection::R) :
				dest.x += dist;
				break ;
			case (common::eDirection::DR) :
				dest.y += dist;
				dest.x += dist;
				break ;
			case (common::eDirection::D) :
				dest.y += dist;
				break ;
			case (common::eDirection::DL) :
				dest.y += dist;
				dest.x -= dist;
				break ;
			case (common::eDirection::L) :
				dest.x -= dist;
				break ;
			case (common::eDirection::UL) :
				dest.y -= dist;
				dest.x -= dist;
				break ;
		}
		return (getCell(dest));
	}

	inline virtual int8_t	countAlign(const common::vec2 &stroke, common::eDirection dir, common::eCell player) const
	{
		bool				permissive(true);
		int8_t				leftSide = _countAlignSide(stroke, dir, player, permissive);
		int8_t				rightSide = _countAlignSide(stroke, common::opposite(dir), player, permissive);

		if (leftSide == -1 || rightSide == -1)
			return (-1);
		return (leftSide + rightSide);
	}

private:
	common::eCell			m_board[N][N];

	static inline bool		_isValid(const common::vec2 &stroke) {return (stroke.x >= 0 && stroke.x < N && stroke.y >= 0 && stroke.y < N);};

	inline virtual int8_t	_countAlignSide(const common::vec2 &stroke, common::eDirection dir, common::eCell player, bool &permissive) const
	{
		int					n;

		n = 0;
		while (++n < N)
		{
			auto	cell = getCell(stroke, dir, n);
			if (cell == player)
				continue ;
			else if (cell == common::eCell::NONE)
			{
				auto	nextCell = getCell(stroke, dir, n + 1);
				if (permissive && nextCell == player)
				{
					permissive = false;
					++n;
				}
				else
					return (n - 1);
			}
			else // NONE || E_CELL (=out of range)
				return (-1);
		}
		return (0);
	}

};

#endif
