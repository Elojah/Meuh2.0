#ifndef BOARD_H
# define BOARD_H

# define BOARD_SIZE 19

# include "Cell.hpp"

class Board
{
public:
	Board(void);
	~Board(void);

	void		display(void);
protected:
private:
	Board(Board const &src);
	Board&	operator=(Board const &rhs);

	Cell		_cells[BOARD_SIZE][BOARD_SIZE];
};

#endif
