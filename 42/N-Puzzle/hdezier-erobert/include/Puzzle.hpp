#ifndef PUZZLE_H
# define PUZZLE_H

# define MAX_SIZE 4
# define EMPTY _empty[0]][_empty[1]
# define INC inc[0]][inc[1]

# include <vector>
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

	typedef struct				sCase {
		unsigned int			value;
		unsigned int			dist;
		unsigned int			result;
	}							tCase;

	enum {
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

	void						parse(std::istream &is);
	void						move(char);
	void						resolve(void);

	tCase						_map[MAX_SIZE][MAX_SIZE];
	unsigned int				_empty[2];
	unsigned int				_size;
	std::vector<IHeuristic *>	_h;
	Puzzle						&operator=(Puzzle const &p);
};

#endif
