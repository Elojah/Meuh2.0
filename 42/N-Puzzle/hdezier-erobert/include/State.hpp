
#ifndef STATE_H
# define STATE_H

# define EMPTY_VALUE 0
# define MAX_SIZE 256
# define MAX_CASE 65536
# define NONE_SET -1

# include <array>

class State
{
public:
	typedef std::array<int, MAX_CASE>		tArray;

	State(void);
	State(State const &s);
	State(size_t size, std::array<int, MAX_CASE> const &map);
	State(State const &s, char dir);
	~State(void);

	State									&operator=(State const &s);
	bool									operator==(State const &s) const;

	size_t									getId(void) const;
	tArray									getMap(void) const;
	size_t									getDepth(void) const;
	void									setDepth(unsigned int depth);
	size_t									getSize(void) const;
	int										getValue(void) const;
	void									setValue(int);
	size_t									getPrevious(void) const;
	void									setPrevious(size_t);
	size_t									getEmptyPos(void) const;

	void									display(void) const;
	void									move(char const dir);
	std::array<State *, 5>					expand(void) const;
	void									finalFillArray(void);
private:
	enum eMove
	{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
	};

	size_t									_id;
	tArray									_map;
	size_t									_size;
	size_t									_empty;
	int										_value;
	size_t									_depth;
	size_t									_previous;

	static size_t							id;
};

#endif
