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

class Cell
{
public:
	enum eValue
	{
		EMPTY,
		P1,
		P2
	};

	Cell(void);
	~Cell(void);

	const eValue	&getValue(void) const;
	void			init(Cell const **board, int const x, int const y);
	bool			checkCapture(void) const;
protected:
private:
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

	eValue		_value;
	Cell const	*_adjacent[8];

	Cell(Cell const &src);

	Cell			&operator=(Cell const &rhs);

};

#endif
