#include "scop.h"
#include <math.h>

#include <stdio.h>
void		print_obj(t_object *obj)
{
	printf("---------OBJ NAME\t: %s\n", obj->name);
	printf("Vertex:\n");
	for (unsigned int i = 0; i < obj->vertex_buffer_size; ++i)
	{
		printf("\tX: %f\tY: %f\tZ: %f\n"
			, obj->vertex_buffer_data[i].x
			, obj->vertex_buffer_data[i].y
			, obj->vertex_buffer_data[i].z);
	}
	printf("Normal:\n");
	for (unsigned int i = 0; i < obj->normal_buffer_size; ++i)
	{
		printf("\tX: %f\tY: %f\tZ: %f\n"
			, obj->normal_buffer_data[i].x
			, obj->normal_buffer_data[i].y
			, obj->normal_buffer_data[i].z);
	}
	printf("Texture:\n");
	for (unsigned int i = 0; i < obj->tex_buffer_size; ++i)
	{
		printf("\tU: %f\tV: %f\n"
			, obj->tex_buffer_data[i].u
			, obj->tex_buffer_data[i].v);
	}
	printf("Index:\n");
	for (unsigned int i = 0; i < obj->index_buffer_size * 3; i += 3)
	{
		printf("_____\n\tV: %u\tT: %u\tN: %u\n"
			, obj->ve_index_buffer_data[i]
			, obj->te_index_buffer_data[i]
			, obj->no_index_buffer_data[i]);
		printf("\tV: %u\tT: %u\tN: %u\n"
			, obj->ve_index_buffer_data[i + 1]
			, obj->te_index_buffer_data[i + 1]
			, obj->no_index_buffer_data[i + 1]);
		printf("\tV: %u\tT: %u\tN: %u\n"
			, obj->ve_index_buffer_data[i + 2]
			, obj->te_index_buffer_data[i + 2]
			, obj->no_index_buffer_data[i + 2]);
	}
}

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

static void	refresh_vp(t_window *w)
{
	static float	vp[4][4];
	short	i;
	short	j;
	short	n;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			vp[i][j] = 0.0f;
			n = -1;
			while(++n < 4)
				vp[i][j] += w->cam.view[i][n] * w->cam.proj[n][j];
		}
	}
	w->cam.mvp_id = glGetUniformLocation(w->prog_id, "vp");
}

static void	refresh_eye(float row[4], t_point *eye)
{
	row[3] = -row[0] * eye->x - row[1] * eye->y - row[2] * eye->z + 1;
}

static void	refresh_cam(t_camera *cam)
{
	t_point		f;

	f.x = cam->eye.x - cam->pos.x;
	f.y = cam->eye.y - cam->pos.y;
	f.z = cam->eye.z - cam->pos.z;
	normalize(&f);
	normalize(&(cam->up));
	cam->view[3][0] = cam->view[3][1] = cam->view[3][2] = 0.0f;
	cam->view[3][3] = 1.0f;
	cam->view[0][0] = (f.y * cam->up.z) - (f.z * cam->up.y);
	cam->view[0][1] = (f.z * cam->up.x) - (f.x * cam->up.z);
	cam->view[0][2] = (f.x * cam->up.y) - (f.y * cam->up.x);
	cam->view[1][0] = (cam->view[0][1] * f.z) - (cam->view[0][2] * f.y);
	cam->view[1][1] = (cam->view[0][2] * f.x) - (cam->view[0][0] * f.z);
	cam->view[1][2] = (cam->view[0][0] * f.y) - (cam->view[0][1] * f.x);
	cam->view[2][0] = -f.x;
	cam->view[2][1] = -f.y;
	cam->view[2][2] = -f.z;
	refresh_eye(cam->view[0], &(cam->eye));
	refresh_eye(cam->view[1], &(cam->eye));
	refresh_eye(cam->view[2], &(cam->eye));
}

#include <stdio.h>
static void	refresh(t_window *w)
{
	refresh_cam(&(w->cam));
	refresh_vp(w);
	printf("mvpid: %d\n", w->cam.mvp_id);
}

void		loop(t_window *w)
{
	double	t;
	double	prev_t;

	print_obj(&(w->obj));
	// glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	refresh(w);
	render(w);
	while (!glfwWindowShouldClose(w->window))
	{
		if ((t = glfwGetTime()) < prev_t + REFRESH_TIME)
			continue ;
		prev_t = t;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		refresh(w);
		render(w);
		glfwSwapBuffers(w->window);
		glfwPollEvents();
	}
}
