// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GUIGL.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/27 14:56:40 by erobert           #+#    #+#             //
//   Updated: 2015/04/27 16:41:00 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GUI_GL_H
# define GUI_GL_H

# define GL_GLEXT_PROTOTYPES
# include <vector>
# include <string>
# include <OpenGL/gl3.h>
# define __gl_h_
# include <GLFW/glfw3.h>
# define GLFW_INCLUDE_GLCOREARB
# include <iostream>
# include "IGUINibbler.hpp"

# define BUFFER_OFFSET(i) ((char *)NULL + (i))
# define SIZE_CASE 40

class GUIGL : public IGUINibbler
{
public:
	GUIGL(void);
	virtual ~GUIGL(void);

	void					setKey(char c);

	virtual void			initMap(std::vector<int> const &map,
									int height, int width);
	virtual void			updateDisplay(tNibbler const &tN, int apple,
										  int score);
	virtual Game::eEvent	getEvent(void);
private:
	struct sPoint
	{
		GLfloat x;
		GLfloat y;
	};

	GLFWwindow				*_window;
	std::size_t				_width;
	std::size_t				_height;
	std::vector<int>		_map;
	GLuint					_vertexBuffer;
	GLuint					_indexBuffer;
	GLuint					_vertexArrayID;
	GLuint					_progID;
	sPoint					*_vertexBufferData;
	GLuint					*_indexBufferData;
	int						_key;
	char					_input[Game::E_EVENT];

	GUIGL(GUIGL const &src);

	GUIGL					&operator=(GUIGL const &rhs);

	static void				keyCallback(GLFWwindow* window, int key,
										int scancode, int action, int mods);
	void					initBuffers(void);
};

extern "C"
{
	GUIGL					*createGUI(void);
	void					deleteGUI(GUIGL *gN);
}

#endif
