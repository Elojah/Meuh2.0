#ifndef STATE_H
# define STATE_H

# define MAX_SIZE 4
# define EMPTY _empty[0]][_empty[1]
# define INC inc[0]][inc[1]

class State
{
public:
	State(unsigned int);
	~State(void);
	void						move(char const);
protected:
private:
	State(void);
	int							_map[MAX_SIZE][MAX_SIZE];
	unsigned int				_size;
	unsigned int				_empty[2];
};

#endif
