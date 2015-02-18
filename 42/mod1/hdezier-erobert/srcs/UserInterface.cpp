// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   UserInterface.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/02/05 17:05:41 by erobert           #+#    #+#             //
//   Updated: 2015/02/12 14:28:53 by erobert          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "UserInterface.hpp"

UserInterface::UserInterface(std::string const &name)
{
	XVisualInfo				*xVI;
	XSetWindowAttributes	xSWA;
	GLint					att[] = {GLX_RGBA,
									 GLX_DEPTH_SIZE,
									 24,
									 GLX_DOUBLEBUFFER,
									 None};

	_display = XOpenDisplay(NULL);
	if (!_display)
	{
		std::cerr << "OpenDisplay error" << std::endl;
		return ;
	}
	_root = DefaultRootWindow(_display);
	xVI = glXChooseVisual(_display, 0, att);
	if (!xVI)
	{
		std::cerr << "glXChooseVisual error" << std::endl;
		return ;
	}
	xSWA.colormap = XCreateColormap(_display, _root, xVI->visual, AllocNone);
	xSWA.event_mask = ExposureMask | KeyPressMask;
	_window = XCreateWindow(_display, _root, 0, 0, 1024, 768, 0,
							xVI->depth, InputOutput, xVI->visual,
							CWColormap | CWEventMask, &xSWA);
	XMapWindow(_display, _window);
	XStoreName(_display, _window, name.c_str());
	_gLXC = glXCreateContext(_display, xVI, NULL, GL_TRUE);
	glXMakeCurrent(_display, _window, _gLXC);
	glEnable(GL_DEPTH_TEST);
}
UserInterface::~UserInterface(void)
{
	glXMakeCurrent(_display, None, NULL);
	glXDestroyContext(_display, _gLXC);
	XDestroyWindow(_display, _window);
	XCloseDisplay(_display);
}

void		UserInterface::addObject(IObject *o)
{
	_obj.push_front(o);
}
void		UserInterface::drawLoop(void)
{
	XEvent					xE;
	XWindowAttributes		xWA;
	float					z(-400);
	bool					expose(false);

	while (1138)
	{
        XNextEvent(_display, &xE);
        if(xE.type == Expose || expose)
		{
			XGetWindowAttributes(_display, _window, &xWA);
			glViewport(0, 0, xWA.width, xWA.height);

			glClearColor(0.0, 0.0, 0.0, 0.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-1. + z, 1. - z, -1. + z , 1. - z, 1., 200.);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(20, -20, 300, 250, 250, 0, 0.0, 0.0, 1.0);
			// gluLookAt(405., -400., 10., 400, -400., 0., 0., 1., 0.);

			glBegin(GL_TRIANGLE_STRIP);
			_obj.front()->drawObject();
			glEnd();
			glXSwapBuffers(_display, _window);
			expose = false;
        }
		else if (xE.type == KeyPress)
		{
			if (xE.xkey.keycode == ESC)
				return ;
			else if (xE.xkey.keycode == MINUS)
				z -= 50;
			else if (xE.xkey.keycode == PLUS)
				z += 50;
			expose = true;
		}
	}
}

