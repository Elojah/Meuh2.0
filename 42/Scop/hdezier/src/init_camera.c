#include "scop.h"
#include <math.h>

static void	init_projection(t_camera *cam)
{
	float			depth;
	short			i;
	short			j;

	i = -1;
	depth = 1.0f / (VIEW_NEAR - VIEW_FAR);
	while (++i < 4)
	{
		j = -1;
		while(++j < 4)
			cam->proj[i][j] = 0.0f;
	}
	cam->proj[1][1] = 1.0f / (float)tan(RAD(VIEW_FAR / 2.0f));
	cam->proj[0][0] = cam->proj[1][1] / VIEW_ASPECT;
	cam->proj[2][2] = (VIEW_NEAR + VIEW_FAR) * depth;
	cam->proj[2][3] = 2 * VIEW_FAR * VIEW_NEAR * depth;
	cam->proj[3][2] = -1.0f;
}

void		init_camera(t_camera *cam)
{
	cam->pos = (t_point){1.0f, 1.0f, 10.0f};
	cam->eye = (t_point){1.0f, 1.0f, -10.0f};
	cam->up = (t_point){1.0f, 0.0f, 0.0f};
	init_projection(cam);
}
