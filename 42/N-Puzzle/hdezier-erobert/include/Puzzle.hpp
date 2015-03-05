#ifndef PUZZLE_H
# define PUZZLE_H

# define BUF_SIZE 1024
# define MAX_SIZE 4
# define EMPTY _empty[0]][_empty[1]
# define INC inc[0]][inc[1]

# include <vector>
# include <array>
# include <iostream>

class IHeuristic;

class Puzzle
{
public:
	Puzzle(std::istream &is);
	~Puzzle(void);
protected:
private:
	Puzzle(void);

	enum eMove
	{
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

	void						parseFile(std::ifstream &ifs);
	void						resolve(void);

	state						_initMap;
	state						_finalMap;
	unsigned int				_size;
	std::vector<IHeuristic *>	_h;
	Puzzle						&operator=(Puzzle const &p);
};

#endif
