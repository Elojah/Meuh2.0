#ifndef PLAYER_H
# define PLAYER_H

class Board;

class Player
{
public:
	Player(void);
	~Player(void);

	struct		vec2
	{
		unsigned int	x;
		unsigned int	y;
	};

	const vec2		&play(Board const &b, vec2 const &event);
protected:
private:
	Player(Player const &src);
	Player&	operator=(Player const &rhs);
};

#endif
