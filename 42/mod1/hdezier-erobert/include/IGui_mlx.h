#ifndef I_GUI_MLX_H
# define I_GUI_MLX_H

# include "IGui.h"

class IGui_mlx : public IGui
{
public:
	IGui_mlx(void);
	~IGui_mlx(void);
	void	init_window(void);
	void	loop(void);
protected:
private:
	typedef struct		s_window
	{
		unsigned int	h;
		unsigned int	w;
		char			name[32];
		void			*ptr;
	}					t_window;

	void		*mlx_ptr;
	t_window	win;
	void		*img;
};

#endif

