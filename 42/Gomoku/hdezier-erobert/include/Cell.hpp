// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cell.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:08:43 by hdezier           #+#    #+#             //
//   Updated: 2015/05/28 12:09:32 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CELL_HPP
# define CELL_HPP

# define OPPONENT(n) (((n) == Cell::P1 ? Cell::P2 : Cell::P1))
# define OPPOSITE(n) ((n) < 4 ? (n) + 4 : (n) - 4)
# define CAST_DIR(i) static_cast<Cell::eAdjacent>(i)
# define BOARD_SIZE 19

class Cell
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

	Cell(void);
	~Cell(void);

	const eValue	&getValue(void) const;
	void			setValue(Cell::eValue const &e);

	void			setAdjacentsValue(Cell::eValue const &e, int n,
										Cell::eAdjacent const &dir);

	bool			isPlayable(void) const;
	void			setPlayableDirection(int dist, Cell::eAdjacent const &dir);

	void			init(Cell board[BOARD_SIZE][BOARD_SIZE], int size,
						int const x, int const y);

	int				checkCapture(void) const;
	int				countAlign(eValue const &value, Cell::eAdjacent const &dir) const;
	Cell			*operator[](Cell::eAdjacent const &e);
	int				countFreeThrees(eValue const &value, Cell::eAdjacent const &dir,
									eValue const &permissiveValue, int &nPermissive);
	Cell const		*getNCellDirection(int n, Cell::eAdjacent const &dir) const;

	bool			isCapturable(void) const;
	bool			isCapturableDirection(Cell::eAdjacent dir,
									Cell::eValue const &value) const;
protected:
private:
	eValue				_value;
	Cell				*_adjacent[8];
	bool				_isPlayable;
	static const int	_xIndex[8];
	static const int	_yIndex[8];


	Cell(Cell const &src);
	Cell			&operator=(Cell const &rhs);
};

#endif
