#include "GUIGL.hpp"
#include <iostream>
#include "LoadShaders.h"

GUIGL::GUIGL(void) {
	_input[Game::PAUSE] = 'e';
	_input[Game::RESTART] = 'r';
	_input[Game::EXIT] = 'q';
	_input[Game::UP] = 'w';
	_input[Game::LEFT] = 'a';
	_input[Game::DOWN] = 's';
	_input[Game::RIGHT] = 'd';
	_input[Game::F1] = '1';
	_input[Game::F2] = '2';
	_input[Game::F3] = '3';
}

GUIGL::GUIGL(GUIGL const &src) {
	if (this != &src) {
		*this = src;
	}
}

GUIGL::~GUIGL(void) {

	delete _vertex_buffer_data;
	delete _index_buffer_data;

	glDeleteBuffers(1, &_vertexBuffer);
	glDeleteBuffers(1, &_indexBuffer);
	glDeleteVertexArrays(1, &_vertexArrayID);
	glDeleteProgram(_progID);

	glfwDestroyWindow(_window);
	glfwTerminate();
}

GUIGL		&GUIGL::operator=(GUIGL const &rhs) {
	if (this != &rhs) {
		_window = rhs._window;
		_width = rhs._width;
		_height = rhs._height;
		_map = rhs._map;
	}
	return (*this);
}

void			GUIGL::initMap(std::vector<int> const &map,
									int height, int width) {
	_map = map;
	_height = height;
	_width = width;
	if (!glfwInit()) {
	    exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	_window = glfwCreateWindow(_width * SIZE_CASE, _height * SIZE_CASE, "Nibbler", NULL, NULL);
	glfwMakeContextCurrent(_window);
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetWindowUserPointer(_window, this);
	glfwSwapInterval(1);
	glfwSetKeyCallback(_window, keyCallback);
	glClearColor(0.1, 0.25, 0.66, 0.3);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	initBuffers();
}

void			GUIGL::initBuffers(void) {
	size_t				n(0);

	_vertex_buffer_data = new sPoint[_width * _height + 1];
	_index_buffer_data = new GLuint[(_width * _height + 1) * 4];

	/*
	**Vertex
	*/
	for (size_t i = 0; i < _width; ++i) {
		for (size_t j = 0; j < _height; ++j) {
			_vertex_buffer_data[i].x = (static_cast<float>(i) - (_width / 2)) / _width * 2.0f;
			_vertex_buffer_data[i].y = (static_cast<float>(j) - (_height / 2)) / _height * 2.0f;
			std::cout << "Vx:\t" << _vertex_buffer_data[i].x << "\t\t";
			std::cout << "Vy:\t" << _vertex_buffer_data[i].y << std::endl;
		}
	}

	/*
	**Index
	*/
	for (size_t i = 0; i < _width * (_height - 1); ++i) {
		n = i * 4;
		_index_buffer_data[n] = i;
		_index_buffer_data[n + 1] = i + 1;
		_index_buffer_data[n + 2] = i;
		_index_buffer_data[n + 3] = i + _width;
	}

	glGenVertexArrays(1, &_vertexArrayID);
	glBindVertexArray(_vertexArrayID);

	_progID = LoadShaders("./gui_gl/src/shaders/Grid.vert", "./gui_gl/src/shaders/Grid.frag");

	glGenBuffers(1, &_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, (_width * _height + 1) * 2 * sizeof(GLfloat), _vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ((_width * _height + 1) * 4) * sizeof(GLuint), _index_buffer_data, GL_STATIC_DRAW);
	glUseProgram(_progID);
}

void			GUIGL::updateDisplay(tNibbler const &tN, int apple, int score) {
	(void)tN;
	(void)apple;
	(void)score;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);

	glDrawElements(
		GL_LINE_STRIP,
		_width * _height * 4,
		GL_UNSIGNED_INT,
		BUFFER_OFFSET(0)
	);
	// glDrawArrays(GL_POINTS, 0, _width * _height);

	glDisableVertexAttribArray(0);

	glfwSwapBuffers(_window);
	glfwPollEvents();//Needed, or you will get a spinning beach ball
}

Game::eEvent	GUIGL::getEvent(void) {
	int			i;

	if (_key != 0) {
		i = 0;
		while (i < Game::E_EVENT)
		{
			if (_input[i] == _key) {
				_key = 0;
				return (static_cast<Game::eEvent>(i));
			}
			i++;
		}
	}
	return (Game::UP);
}

void		GUIGL::setKey(char c) {
	_key = c;
}


void		GUIGL::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	static bool			keyValid;
	static GUIGL		*win = static_cast<GUIGL *>(glfwGetWindowUserPointer(window));

	(void)scancode;
	(void)mods;

	keyValid = (action == GLFW_PRESS || action == GLFW_REPEAT);
	if (!keyValid) {
		return ;
	}
	win->setKey(key);
}

GUIGL							*createGUI(void) {
	return (new GUIGL);
}

void							deleteGUI(GUIGL *gN) {
	delete gN;
}
