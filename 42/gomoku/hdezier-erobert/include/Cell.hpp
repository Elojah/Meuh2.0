#ifndef CELL_H
# define CELL_H


class Cell
{
public:
	Cell(void);
	~Cell(void);

	enum eValue
	{
		EMPTY,
		P1,
		P2
	};

protected:
private:
	Cell(Cell const &src);
	Cell&	operator=(Cell const &rhs);

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

	eValue	_value;
	Cell	*_adjacent[8];
	void	init(Cell const **board, int const x, int const y);
};

#endif
