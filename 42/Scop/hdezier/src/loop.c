#include "scop.h"

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

static void	set_center_obj(t_object *obj)
{
	t_point			max;
	t_point			min;
	unsigned int	i;

	max.x = max.y = max.z = i = 0;
	min.x = min.y = min.z = 0xFFFFFFFF;
	while (i < obj->vertex_buffer_size)
	{
		if (obj->vertex_buffer_data[i].x > max.x)
			max.x = obj->vertex_buffer_data[i].x;
		else if (obj->vertex_buffer_data[i].x < min.x)
			min.x = obj->vertex_buffer_data[i].x;
		if (obj->vertex_buffer_data[i].y > max.y)
			max.y = obj->vertex_buffer_data[i].y;
		else if (obj->vertex_buffer_data[i].y < min.y)
			min.y = obj->vertex_buffer_data[i].y;
		if (obj->vertex_buffer_data[i].z > max.z)
			max.z = obj->vertex_buffer_data[i].z;
		else if (obj->vertex_buffer_data[i].z < min.z)
			min.z = obj->vertex_buffer_data[i].z;
		i++;
	}
	obj->center.x = min.x + ABS(max.x - min.x) / 2;
	obj->center.y = min.y + ABS(max.y - min.y) / 2;
	obj->center.z = min.z + ABS(max.z - min.z) / 2;
}

void		loop(t_window *w)
{
	double	t;
	double	prev_t;

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	set_center_obj(&(w->obj));
	refresh(w);
	render(w);
	while (!glfwWindowShouldClose(w->window))
	{
		if ((t = glfwGetTime()) < prev_t + REFRESH_TIME)
			continue ;
		prev_t = t;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render(w);
		glfwSwapBuffers(w->window);
		glfwPollEvents();
	}
}
