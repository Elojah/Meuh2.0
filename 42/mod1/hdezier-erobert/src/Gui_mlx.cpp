#include "Gui_mlx.h"

Gui_mlx::Gui_mlx()
{
	std::strcpy(this->win.name, "Test");
	this->win.h = 600;
	this->win.w = 800;
	this->mlx_ptr = mlx_init();
	this->img = mlx_new_image(this->mlx_ptr, this->win.w, this->win.h);
}

Gui_mlx::~Gui_mlx()
{
	;
}

void	Gui_mlx::init_window(void)
{
	this->win.ptr = mlx_new_window(this->mlx_ptr, this->win.w, this->win.h, this->win.name);
}
