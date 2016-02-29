// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Board.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:07:33 by hdezier           #+#    #+#             //
//   Updated: 2015/06/10 16:19:06 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 19
# define OPPONENT(n) (((n) == Board::P1 ? Board::P2 : Board::P1))
# define OPPOSITE(n) ((n) < 4 ? (n) + 4 : (n) - 4)
# define CAST_DIR(i) static_cast<Board::eAdjacent>(i)

# include <unistd.h>
# include "Player.hpp"

class Board
{
public:
	enum eValue
	{
		EMPTY = 0,
		P1,
		P2,
		E_VALUE
	};
	enum eAdjacent
	{
		UP = 0,
		UP_RIGHT,
		RIGHT,
		DOWN_RIGHT,
		DOWN,
		DOWN_LEFT,
		LEFT,
		UP_LEFT,
		E_ADJACENT
	};

	struct sCell
	{
		eValue			value;
		bool			isPlayable;
		struct sCell	*adjacent[8];
	};

	Board(void);
	~Board(void);

	Board(Board const &rhs);
	Board		&operator=(Board const &rhs);

	unsigned int		size(void) const;

	void				init(unsigned int size);
	void				display(void) const;
	eValue				getValue(int row, int col) const;
	sCell				&getCell(int row, int col);
	sCell const			&getCell(int row, int col) const;
	void				updateHeuristics(int row, int col);

	
	void				setPlayableDirection(sCell *cell, int dist,
											 eAdjacent dir);
	int					countAlign(sCell const *cell, eValue value,
								   eAdjacent dir) const;
	int					countFreeThrees(sCell *cell, eValue value,
										eAdjacent dir,
										eValue permissiveValue,
										int &nPermissive);
	bool				isCapturable(sCell const *cell) const;
	bool				isCapturableDirection(sCell const *cell, eAdjacent dir,
											  eValue value) const;
	sCell const			*getNCellDirection(sCell const *cell, int n,
										   eAdjacent dir) const;
	int					checkCapture(sCell const &cell) const;
	void				setAdjacentsValue(sCell *cell, eValue e, int n,
										  eAdjacent dir);
	
private:
	int					_size;
	static const int	_xIndex[8];
	static const int	_yIndex[8];

	sCell				_cells[BOARD_SIZE * BOARD_SIZE];
};

#endif
