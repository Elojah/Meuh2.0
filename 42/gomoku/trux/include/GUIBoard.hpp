#ifndef G_U_I_BOARD_H
# define G_U_I_BOARD_H

# include "SFML/Graphics.hpp"
# define WIDTH 1024
# define HEIGHT 1024

class GUIBoard
{
public:
	GUIBoard(void);
	~GUIBoard(void);
	void	init(int size);
	void	render(void);
	int		getEvent(void);


	enum eEvent
	{
		EXIT,
		MOUSE,
		KEY,
		E_EVENT
	};

	struct		sEvent
	{
		eEvent	key;
		char	c;
		int		x;
		int		y;
	};
protected:
private:
	GUIBoard(GUIBoard const &rhs);
	GUIBoard&	operator=(GUIBoard const &rhs);

	size_t				_size;
	sf::RenderWindow	_window;
	sf::Event			_event;
	sf::Texture			_tBoard;
	sf::Sprite			_sBoard;

};

#endif
