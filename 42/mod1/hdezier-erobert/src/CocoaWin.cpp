#include "CocoaWin.hpp"
#include "IObject.hpp"
#include "Camera.hpp"
#include <iostream>

CocoaWin::CocoaWin(void) {
}

CocoaWin::CocoaWin(std::size_t width, std::size_t height) :
															_width(width),
															_height(height)
{
	this->init();
}

CocoaWin::~CocoaWin(void) {
	std::cout << "Credits:" << std::endl
	<< "\terobert" << std::endl
	<< "\thdezier" << std::endl
	<< "@42SchoolProject" << std::endl;
}

void		CocoaWin::init(void) {
	glClearColor(0, 0.5, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
}

void		CocoaWin::loop(std::vector<IObject *> &objects) {
	Camera			cam;

	while (true) {
		cam.setView();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for (std::vector<IObject *>::iterator it = objects.begin(); it != objects.end(); ++it) {
			(*it)->draw();
		}

		if (glGetError() == GL_NO_ERROR) {
			// std::cout << "Rendering... OK" << std::endl;
		} else {
			std::cout << "Rendering... ERROR" << std::endl;
		}
		switch (_e) {
			case 21: cam.zoom(-0.05);
					break ;
			case 8: cam.rotateAround(0.05);
					break ;
			case 9: cam.zoom(0.05);
					break ;
			case 10: cam.rotateAround(-0.05);
					break ;
			case 61: return ;
			default: loopObjects(_e, objects);
					break ;
		}
	}
}

void	CocoaWin::loopObjects(int const key, std::vector<IObject *> &objects) {
	for (std::vector<IObject *>::iterator it = objects.begin(); it != objects.end(); ++it) {
		if ((*it)->loop(key)) {
			break ;
		}
	}
}
