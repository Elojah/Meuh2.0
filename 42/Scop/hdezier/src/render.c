#include "scop.h"

static void			render_obj(t_object *obj)
{
	glUseProgram(obj->prog_id);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, obj->vertex_buffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ve_index_buffer);
	glDrawElements(
		GL_TRIANGLE_STRIP,
		obj->index_buffer_size,
		GL_UNSIGNED_INT,
		BUFFER_OFFSET(0)
	);
	// glDrawArrays(GL_TRIANGLES, 0, obj->vertex_buffer_size);
	glDisableVertexAttribArray(0);
}

void				render(t_window *w)
{
	render_obj(&(w->obj));
}
