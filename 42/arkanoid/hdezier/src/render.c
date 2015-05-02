#include "arkanoid.h"

void				render(t_window *w)
{
	glUseProgram(w->display.prog_ID);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, w->display.vertex_buffer);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ARRAY_BUFFER, w->map_ID);
	glVertexAttribPointer(1, 1, GL_INT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, w->display.index_buffer);
	glDrawElements(
		GL_TRIANGLE_STRIP,
		WIDTH_MAP * HEIGHT_MAP * 6,
		GL_UNSIGNED_INT,
		BUFFER_OFFSET(0)
	);
	glDisableVertexAttribArray(0);
}
