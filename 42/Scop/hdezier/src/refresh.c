#include "scop.h"
#include <math.h>

static void	normalize(t_point *p)
{
	float	norm;

	norm = sqrt(SQ(p->x) + SQ(p->y) + SQ(p->z));
	if (norm == 1.0f)
		return ;
	p->x /= norm;
	p->y /= norm;
	p->z /= norm;
}

#include <stdio.h>
static void	refresh_vp(t_window *w)
{
	static float	vp[4][4];
	short			i;
	short			j;
	short			n;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			vp[i][j] = 0.0f;
			n = -1;
			while(++n < 4)
				vp[i][j] += w->cam.proj[i][n] * w->cam.view[n][j];
		}
	}
		printf("\n");
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
			printf("%f\t", vp[i][j]);
		printf("\n");
	}
		printf("\n");
	w->cam.mvp_id = glGetUniformLocation(w->prog_id, "vp");
}

static void	refresh_eye(float row[4], t_point *eye)
{
	row[3] = -(row[0] * eye->x + row[1] * eye->y + row[2] * eye->z + 1);
}

static void	refresh_view(t_camera *cam)
{
	t_point		f;

	f.x = cam->pos.x - cam->eye.x;
	f.y = cam->pos.y - cam->eye.y;
	f.z = cam->pos.z - cam->eye.z;
	normalize(&f);
	normalize(&(cam->up));
	cam->view[3][0] = cam->view[3][1] = cam->view[3][2] = 0.0f;
	cam->view[3][3] = 1.0f;
	cam->view[0][0] = (f.y * cam->up.z) - (f.z * cam->up.y);
	cam->view[0][1] = (f.z * cam->up.x) - (f.x * cam->up.z);
	cam->view[0][2] = (f.x * cam->up.y) - (f.y * cam->up.x);
	cam->view[1][0] = cam->up.x = (cam->view[0][1] * f.z) - (cam->view[0][2] * f.y);
	cam->view[1][1] = cam->up.y = (cam->view[0][2] * f.x) - (cam->view[0][0] * f.z);
	cam->view[1][2] = cam->up.z = (cam->view[0][0] * f.y) - (cam->view[0][1] * f.x);
	cam->view[2][0] = -f.x;
	cam->view[2][1] = -f.y;
	cam->view[2][2] = -f.z;
}

static void	refresh_cam(t_camera *cam)
{
	refresh_view(cam);
	refresh_eye(cam->view[0], &(cam->eye));
	refresh_eye(cam->view[1], &(cam->eye));
	refresh_eye(cam->view[2], &(cam->eye));
}

void	refresh(t_window *w)
{
	refresh_cam(&(w->cam));
	refresh_vp(w);
}
