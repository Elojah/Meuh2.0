#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H

# include "Board.hpp"
# include "Player.hpp"
# include "UserInterface.hpp"

class GameManager
{
public:
	GameManager(void);
	~GameManager(void);

	void				init(void);
	void				loop(void);
	const Player::vec2	&eventHandler(void);
protected:
private:
	GameManager(GameManager const &src);
	GameManager&	operator=(GameManager const &rhs);

	Board			_b;
	Player			_p1;
	Player			_p2;
	UserInterface	_ui;
};

#endif
