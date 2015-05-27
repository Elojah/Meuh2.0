#ifndef RULES_H
# define RULES_H

# include "Player.hpp"
# include "GameManager.hpp"

class Board;

class Rules
{
public:
	Rules(void);
	~Rules(void);

	static bool		makeMove(Board const &b
		, Player::vec2 const &move, GameManager::eTurn const &player);
protected:
private:
	Rules(Rules const &src);
	Rules&	operator=(Rules const &rhs);
};

#endif
