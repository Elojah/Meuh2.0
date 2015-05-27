#ifndef PLAYER_H
# define PLAYER_H


class Player
{
public:
	Player(void);
	~Player(void);

	struct sMove
	{
		unsigned int x;
		unsigned int y;
	};

	sMove			&getMove(void);
protected:
private:
	Player(Player const &src);
	Player&	operator=(Player const &rhs);

	bool			_ia;
};

#endif
