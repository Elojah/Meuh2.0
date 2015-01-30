#include "IGui_mlx.h"
#include "mlx.h"
#include <cstring>


IGui_mlx::IGui_mlx()
{
	std::strcpy(this->win.name, "Test");
	this->win.h = 600;
	this->win.w = 800;
	this->mlx_ptr = mlx_init();
	this->img = mlx_new_image(this->mlx_ptr, this->win.w, this->win.h);
}

IGui_mlx::~IGui_mlx()
{
	;
}

void	IGui_mlx::init_window(void)
{
	this->win.ptr = mlx_new_window(this->mlx_ptr, this->win.w, this->win.h, this->win.name);
}

void	IGui_mlx::loop(void)
{
	// mlx_expose_hook(m->win, &draw_window, m);
	// mlx_key_hook(m->win, &get_loop_key, m);
	mlx_loop(this->mlx_ptr);
}
