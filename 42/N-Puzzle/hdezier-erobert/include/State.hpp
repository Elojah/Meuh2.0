#ifndef STATE_H
# define STATE_H

# define EMPTY_VALUE 0
# define MAX_SIZE 256
# define MAX_CASE 65536
# define NONE_SET -1
# define EMPTY _empty[0]][_empty[1]
# define INC inc[0]][inc[1]

#include <array>

class State
{
public:
	State(unsigned int size, std::array<int, MAX_CASE> const &map);
	State(State const&, char dir);
	~State(void);
	void													finalFillArray(void);

	std::array<std::array<int, MAX_SIZE>, MAX_SIZE>			getMap(void) const;
	unsigned int											getDepth(void) const;
	void													setDepth(unsigned int depth);
	unsigned int											getSize(void) const;
	int														getValue(void) const;
	void													setValue(int);
	State													*getPrevious(void) const;
	void													setPrevious(State*);

	void													display(void);
	void													move(char const dir);
	std::array<State *, 4>									expand(void);
	bool													operator==(State const &s) const;
protected:
private:
	typedef std::array<std::array<int, MAX_SIZE>, MAX_SIZE>	mapArray;

	enum eMove
	{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
	};

	State(void);

	mapArray												_map;
	unsigned int											_size;
	unsigned int											_empty[2];
	int														_value;
	unsigned int											_depth;
	State													*_previous;
};

#endif
