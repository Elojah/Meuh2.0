#include "scop.h"

static void	init_projection(t_camera *cam)
{
	float			frustrum;
	float			depth;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	frustrum = VIEW_FAR - VIEW_NEAR;
	depth = 1.0f / frustrum;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
			cam->proj[i][j++] = 0.0f;
		++i;
	}
	cam->proj[1][1] = 1.0f / TAN_MI_FOV;
	cam->proj[0][0] = cam->proj[1][1] / VIEW_ASPECT;
	cam->proj[2][2] = VIEW_FAR * depth;
	cam->proj[2][3] = 1.0f;
	cam->proj[2][2] = -VIEW_FAR * VIEW_NEAR * depth;
}

static void	init_view(t_camera *cam)
{
	(void)cam;
}

void		init_camera(t_camera *cam)
{
	cam->pos = (t_point){10.0f, 10.0f, 20.0f};
	cam->dir = (t_point){1.0f, 0.0f, 0.0f};
	cam->up = (t_point){0.0f, 1.0f, 0.0f};
	init_projection(cam);
	init_view(cam);
}
