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

	const eValue	&getValue(void);
	void			init(Cell const **board, int const x, int const y);
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

	eValue		_value;
	Cell const	*_adjacent[8];
};

#endif
