// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Board.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/28 12:07:33 by hdezier           #+#    #+#             //
//   Updated: 2015/06/01 18:37:53 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 19

# include <unistd.h>
# include "Cell.hpp"
# include "Player.hpp"

class Board
{
public:
	Board(void);
	~Board(void);

	Board(Board const &rhs);
	Board		&operator=(Board const &rhs);

	unsigned int		size(void) const;

	void				setSize(unsigned int size);
	void				display(void) const;
	Cell::eValue const	&getValue(int row, int col) const;
	Cell				&getCell(int row, int col);
	Cell const			&getCell(int row, int col) const;
	void				updateHeuristics(Player::vec2 const &move);
protected:
private:
	unsigned int		_size;

	/*EDIT in one array [BOARD_SIZE * BOARD_SIZE] ?*/
	Cell				_cells[BOARD_SIZE][BOARD_SIZE];
};

#endif
