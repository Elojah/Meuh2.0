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

class Cell
{
public:
	enum eValue
	{
		EMPTY = 0,
		P1,
		P2
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

	void			init(Cell **board, int const x, int const y);
	char			checkCapture(void) const;
protected:
private:
	eValue				_value;
	Cell				*_adjacent[8];
	static const int	_xIndex[8];
	static const int	_yIndex[8];

	int			countValueAligned(eValue const &value, Cell::eAdjacent const &dir);
	Cell const	*getNCellDirection(int n, Cell::eAdjacent const &dir) const;

	Cell(Cell const &src);
	Cell			&operator=(Cell const &rhs);
};

#endif
