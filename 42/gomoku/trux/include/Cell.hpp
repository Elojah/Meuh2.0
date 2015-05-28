#ifndef CELL_H
# define CELL_H

# define SIZE_BOARD 19

struct sCell
{
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
	}

	eCell	value;
	eCell	*adjacent[8];
	void	init(sCell const **board, int const x, int const y);
};

#endif
