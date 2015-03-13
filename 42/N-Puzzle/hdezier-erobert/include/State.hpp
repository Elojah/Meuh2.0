
#ifndef STATE_H
# define STATE_H

# define EMPTY_VALUE 0
# define MAX_SIZE 256
# define MAX_CASE 65536
# define NONE_SET -1
# define EMPTY _empty[0]][_empty[1]
# define INC inc[0]][inc[1]

# include <array>

class State
{
public:
	typedef std::array<int, MAX_SIZE>		tArray;
	typedef std::array<tArray, MAX_SIZE>	tMapArray;

	State(size_t size, std::array<int, MAX_CASE> const &map);
	State(State const &s, char dir);
	~State(void);

	bool									operator==(State const &s) const;

	tMapArray								getMap(void) const;
	size_t									getDepth(void) const;
	void									setDepth(unsigned int depth);
	size_t									getSize(void) const;
	int										getValue(void) const;
	void									setValue(int);
	State									*getPrevious(void) const;
	void									setPrevious(State*);
	std::array<size_t, 2>					getEmptyPos(void) const;

	void									display(void);
	void									move(char const dir);
	std::array<State *, 4>					expand(void);
	void									finalFillArray(void);
private:
	enum eMove
	{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
	};

	State(void);
	State(State const &s);

	State									&operator=(State const &s);

	tMapArray								_map;
	size_t									_size;
	size_t									_empty[2];
	int										_value;
	size_t									_depth;
	State									*_previous;
};

#endif
