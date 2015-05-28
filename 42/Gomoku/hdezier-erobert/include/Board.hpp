// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Board.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:07:33 by hdezier           #+#    #+#             //
//   Updated: 2015/05/28 12:08:30 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 19

# include "Cell.hpp"

class Board
{
public:
	Board(void);
	~Board(void);

	void		display(void);
	Cell		&getCell(int row, int col);
	Cell const	&getCell(int row, int col) const;
protected:
private:
	Board(Board const &src);
	Board		&operator=(Board const &rhs);

	/*EDIT in one array [BOARD_SIZE * BOARD_SIZE] ?*/
	Cell		_cells[BOARD_SIZE][BOARD_SIZE];
};

#endif
