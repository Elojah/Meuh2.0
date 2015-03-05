#ifndef PUZZLE_H
# define PUZZLE_H

# define BUF_SIZE 1024
# define MAX_SIZE 4
# define EMPTY _empty[0]][_empty[1]
# define INC inc[0]][inc[1]

# include <fstream> 
# include <iostream>
# include <sstream>
# include <string>
# include <vector>

class IHeuristic;

class Puzzle
{
public:
	Puzzle(void);
	~Puzzle(void);

	void						parseFile(std::ifstream &ifs);
	void						printPuzzle(void) const;
private:
	struct sCase
	{
		unsigned int			value;
		unsigned int			dist;
		unsigned int			result;
	};
	enum eMove	
	{
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

	Puzzle						&operator=(Puzzle const &p);

	int							parseSize(char *line);
	void						parsePuzzle(char *line, unsigned int i);
	void						move(char);
	void						resolve(void);

	sCase						_map[MAX_SIZE][MAX_SIZE];
	unsigned int				_empty[2];
	unsigned int				_size;
	std::vector<IHeuristic *>	_h;
};

#endif
