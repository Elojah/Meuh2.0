
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

	State(size_t size, std::array<int, MAX_CASE> const &map);
	State(State const &s, char dir);
	~State(void);

	bool									operator==(State const &s) const;

	tArray									getMap(void) const;
	size_t									getDepth(void) const;
	void									setDepth(unsigned int depth);
	size_t									getSize(void) const;
	int										getValue(void) const;
	void									setValue(int);
	State									*getPrevious(void) const;
	void									setPrevious(State*);
	size_t									getEmptyPos(void) const;

	void									display(void);
	void									move(char const dir);
	std::array<State *, 5>					expand(void);
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

	tArray									_map;
	size_t									_size;
	size_t									_empty;
	int										_value;
	size_t									_depth;
	State									*_previous;
};

#endif
