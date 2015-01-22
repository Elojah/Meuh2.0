#ifndef GUI_MLX_H
# define GUI_MLX_H

# include <cstring>
# include "mlx.h"

typedef struct		s_window
{
	unsigned int	h;
	unsigned int	w;
	char			name[32];
	void			*ptr;
}					t_window;

class Gui_mlx
{
public:
	Gui_mlx(void);
	~Gui_mlx(void);
	void	init_window(void);
protected:
private:
	void		*mlx_ptr;
	t_window	win;
	void		*img;
};

#endif

