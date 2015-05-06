#include "scop.h"

static void			render_obj(t_object *obj)
{
	return ;
	glUseProgram(obj->prog_id);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vertex_buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->index_buffer);
	glVertexAttribPointer(1, 3, GL_UNSIGNED_INT, GL_TRUE, 0, BUFFER_OFFSET(0));
	// glDrawElements();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void				render(t_window *w)
{
	render_obj(&w->obj);
}
