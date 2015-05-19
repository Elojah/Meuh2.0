#ifndef GAME_H
# define GAME_H

# define SIZE_BOARD 19

class Game
{
public:
	Game(void);
	~Game(void);
	Game(Game const &src);
	Game&	operator=(Game const &rhs);

	void	launch(void);
	void	loop(void);
protected:
private:
	enum eCase {
		EMPTY = 0,
		P1,
		P2
	};

	int		_board[SIZE_BOARD][SIZE_BOARD];
	bool	_gameOver;
};

#endif