#ifndef PUZZLE_H
# define PUZZLE_H

# define BUF_SIZE 1024
# define MAX_SIZE 4
# define EMPTY _empty[0]][_empty[1]
# define INC inc[0]][inc[1]

<<<<<<< HEAD
# include <fstream> 
=======
# include <vector>
# include <array>
>>>>>>> 035880079f5d85aade86ac559b06452036b89343
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

<<<<<<< HEAD
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
=======
	typedef						int		state[MAX_SIZE][MAX_SIZE];

	enum eMove
>>>>>>> 035880079f5d85aade86ac559b06452036b89343
	{
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	};

<<<<<<< HEAD
	Puzzle						&operator=(Puzzle const &p);

	int							parseSize(char *line);
	void						parsePuzzle(char *line, unsigned int i);
	void						move(char);
=======
	void						parseFile(std::ifstream &ifs);
	void						move(int **, char const);
>>>>>>> 035880079f5d85aade86ac559b06452036b89343
	void						resolve(void);
	unsigned int				heuristicManhattan(unsigned int const, unsigned int const) const;
	bool						isResolved(void);

	state						_initMap;
	state						_finalMap;
	unsigned int				_empty[2];
	unsigned int				_size;
	std::vector<IHeuristic *>	_h;
};

#endif
