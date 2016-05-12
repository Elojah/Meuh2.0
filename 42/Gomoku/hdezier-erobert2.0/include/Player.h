/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 21:00:56 by hdezier           #+#    #+#             */
/*   Updated: 2016/05/10 12:54:41 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define MAX_DEPTH 3

# include "stdint.h"
# include "common.h"
# include "minmax.h"

# include <iostream>

class IBoard;
class Rules;
class UserInterface;

class Player
{
public:
	Player(void) = default;
	virtual ~Player(void) = default;

	inline void				switchAI() {m_ai = !m_ai;};
	inline bool				ai(void) const {return (m_ai);};

	common::vec2			play(const IBoard &board, const Rules &rules,
								const common::vec2 &stroke, const common::eCell &player) const;

	struct					sEval_P1 : public IEval
	{
		inline virtual uint8_t		eval(const IBoard &board, const Rules &rules, const sMinMaxState &minMaxState) const
		{
			static const uint8_t	boardSize = board.getSize();
			uint8_t			result(1);

			const common::eCell win = rules.gameEnded(board, minMaxState.lastStroke, minMaxState.captures[0], minMaxState.captures[1]);
			if (win == common::eCell::P2)
			{
				// std::cout << "Loose incomin..." << std::endl;
				// board.displayBoard();
				return (1);
			}
			else if (win == common::eCell::P1)
			{
				// std::cout << "WIN incomin !" << std::endl;
				// board.displayBoard();
				return (255);
			}
			for (uint8_t i = 0; i < boardSize; ++i)
			{
				for (uint8_t j = 0; j < boardSize; ++j)
				{
					if (board.getCell({i, j}) == common::eCell::NONE)
					{
						for (uint8_t dir = 1; dir < 5; ++dir)
						{
							uint8_t playerMove = board.countAlignFree({i, j}, (common::eDirection)dir, common::eCell::P1);
							uint8_t opponentMove = board.countAlignFree({i, j}, (common::eDirection)dir, common::eCell::P2);
							result += playerMove * playerMove;
							result -= opponentMove * opponentMove;
						}
					}
				}
			}
			result += (minMaxState.captures[1] - minMaxState.captures[0]) * 2;
			return (result);
		}
	};

	struct					sEval_P2 : public IEval
	{
		inline virtual uint8_t		eval(const IBoard &board, const Rules &rules, const sMinMaxState &minMaxState) const
		{
			static const uint8_t	boardSize = board.getSize();
			uint8_t			result(100);

			const common::eCell win = rules.gameEnded(board, minMaxState.lastStroke, minMaxState.captures[0], minMaxState.captures[1]);
			if (win == common::eCell::P1)
			{
				std::cout << "Loose incomin..." << std::endl;
				board.displayBoard();
				return (1);
			}
			else if (win == common::eCell::P2)
			{
				std::cout << "WIN incomin..." << std::endl;
				board.displayBoard();
				return (255);
			}
			for (uint8_t i = 0; i < boardSize; ++i)
			{
				for (uint8_t j = 0; j < boardSize; ++j)
				{
					if (board.getCell({i, j}) == common::eCell::NONE)
					{
						for (uint8_t dir = 1; dir < 5; ++dir)
						{
							result += board.countAlignFree({i, j}, (common::eDirection)dir, common::eCell::P2);
							result -= board.countAlignFree({i, j}, (common::eDirection)dir, common::eCell::P1);
						}
					}
				}
			}
			result += (minMaxState.captures[1] - minMaxState.captures[0]) * 2;
			return (result);
		}
	};

private:
	bool			m_ai = false;

	common::vec2	_calculusAI(const IBoard &board, const Rules &rules,
								const common::eCell &player) const;

	sEval_P1				m_eval_P1;
	sEval_P2				m_eval_P2;
};

#endif
