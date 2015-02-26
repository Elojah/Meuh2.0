#include "X11Win.hpp"
#include "IObject.hpp"
#include <iostream>

X11Win::X11Win(void) {
}

X11Win::X11Win(std::size_t width, std::size_t height) :
															_width(width),
															_height(height)
{
	if (!(_d = XOpenDisplay(NULL))) {
		std::cout << "Error: display environment variable is wrong" << std::endl;
		return ;
	}
	this->init();
}

X11Win::~X11Win(void) {
	glXMakeCurrent(_d, None, NULL);
	glXDestroyWindow(_d, _glxWin);
	XDestroyWindow(_d, _w);
	glXDestroyContext(_d, _ctx);
	XFreeColormap(_d, _cmap);
	XCloseDisplay(_d);
}

void		X11Win::init(void) {
	XSetWindowAttributes				swa;
	XVisualInfo							*vi;
	GLint								v_att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
#ifndef __APPLE__
	glXCreateContextAttribsARBProc	glXCreateContextAttribsARB;
	static int				context_attribs[] = {
		GLX_CONTEXT_MAJOR_VERSION_ARB, 1,
		GLX_CONTEXT_MINOR_VERSION_ARB, 3,
		GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		None
	};
#endif

	// assignBestFBC();
	// if (!(vi = glXGetVisualFromFBConfig(_d, _fbc))) {
	// 	std::cout << "Error: No visual found" << std::endl;
	// } else {
	// 	std::cout << "Chosen visualID: " << vi->visualid << std::endl;
	// }
	vi = glXChooseVisual(_d, 0, v_att);
	swa.colormap = _cmap = XCreateColormap(_d,
												RootWindow(_d, vi->screen),
												vi->visual, AllocNone);
	swa.background_pixmap = None;
	swa.border_pixel = 0;
	swa.event_mask = ExposureMask|KeyPressMask|ButtonPressMask|StructureNotifyMask;
	/*Window XCreateWindow(
	_d, parent, x, y, width, height, border_width, depth,
		class, visual, valuemask, attributes)*/
	_w = XCreateWindow(_d,
							RootWindow(_d, vi->screen)
							, 0
							, 0
							, _width
							, _height
							, 0
							, vi->depth
							, InputOutput
							, vi->visual
							, CWBackPixel|CWBackPixmap|CWBorderPixel|CWColormap|CWEventMask
							, &swa);
	XStoreName(_d, _w, "X11 Window");
	XMapWindow(_d, _w);
	_glxWin = glXCreateWindow(_d, _fbc, _w, NULL);

#ifndef __APPLE__
	glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)glXGetProcAddressARB(
		(const GLubyte *)"glXCreateContextAttribsARB");
	_ctx = glXCreateContextAttribsARB(_d, _fbc, 0, True, context_attribs);
#else
	_ctx = glXCreateContext(_d, vi, NULL, GL_TRUE);
#endif

	XFree(vi);
	XSync(_d, False);
	if (!glXMakeContextCurrent(_d, _w, _w, _ctx)) {
		std::cout << "Error context: Can't make current" << std::endl;
	}
	glClearColor(0, 0.5, 1, 1);
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glXSwapBuffers(_d, _glxWin);
	// glClearColor(0, 0.5, 0.5, 0.5);
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glXSwapBuffers(_d, _glxWin);
	glEnable(GL_DEPTH_TEST);
}
/*
	typedef union				_XEvent {
	int type;
	XAnyEvent xany;
	XKeyEvent xkey;
	XButtonEvent xbutton;
	XMotionEvent xmotion;
	XCrossingEvent xcrossing;
	XFocusChangeEvent xfocus;
	XExposeEvent xexpose;
	XGraphicsExposeEvent xgraphicsexpose;
	XNoExposeEvent xnoexpose;
	XVisibilityEvent xvisibility;
	XCreateWindowEvent xcreatewindow;
	XDestroyWindowEvent xdestroywindow;
	XUnmapEvent xunmap;
	XMapEvent xmap;
	XMapRequestEvent xmaprequest;
	XReparentEvent xreparent;
	XConfigureEvent xconfigure;
	XGravityEvent xgravity;
	XResizeRequestEvent xresizerequest;
	XConfigureRequestEvent xconfigurerequest;
	XCirculateEvent xcirculate;
	XCirculateRequestEvent xcirculaterequest;
	XPropertyEvent xproperty;
	XSelectionClearEvent xselectionclear;
	XSelectionRequestEvent xselectionrequest;
	XSelectionEvent xselection;
	XColormapEvent xcolormap;
	XClientMessageEvent xclient;
	XMappingEvent xmapping;
	XErrorEvent xerror;
	XKeymapEvent xkeymap;
	long pad[24];
}						XEvent;
*/
void		X11Win::loop(std::vector<IObject> &objects) {
	while (true) {
		// glBegin(GL_POLYGON);
		for (std::vector<IObject>::iterator it = objects.begin(); it != objects.end(); ++it) {
			it->draw();
		}
		// glEnd();
		// glFlush();
		glXSwapBuffers(_d, _glxWin);

		if (glGetError() == GL_NO_ERROR) {
			std::cout << "Rendering... OK" << std::endl;
		} else {
			std::cout << "Rendering... ERROR" << std::endl;
		}
		XNextEvent(_d, &_e);
		if (_e.xkey.keycode == 8) {/*A*/
			glXSwapBuffers(_d, _glxWin);
		} else if (_e.xkey.keycode == 61) {/*ESC*/
			break ;
		}
	}
}
/*
GL_NO_ERROR
GL_INVALID_ENUM
GL_INVALID_VALUE
GL_INVALID_OPERATION
GL_INVALID_FRAMEBUFFER_OPERATION
GL_OUT_OF_MEMORY
GL_STACK_UNDERFLOW
GL_STACK_OVERFLOW
*/
void		X11Win::assignBestFBC(void) {
	GLXFBConfig			*tmp_fbc;
	int					fbcount;
	static GLint		v_att[] = {
		// GLX_X_RENDERABLE, True,
		// GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
		// GLX_RENDER_TYPE, GLX_RGBA_BIT,
		// GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
		GLX_RGBA,
		GLX_DEPTH_SIZE, 24,
		GLX_DOUBLEBUFFER,
		// GLX_RED_SIZE, 8,
		// GLX_GREEN_SIZE, 8,
		// GLX_BLUE_SIZE, 8,
		// GLX_ALPHA_SIZE, 8,
		// GLX_STENCIL_SIZE, 8,
		// GLX_DOUBLEBUFFER, True,
		// GLX_SAMPLE_BUFFERS , 1,
		// GLX_SAMPLES, 4,
		None
	};

	tmp_fbc = glXChooseFBConfig(_d, DefaultScreen(_d), v_att, &fbcount);
	if (!tmp_fbc) {
		std::cout << "No framebuffer config found" << std::endl;
	}
	_fbc = tmp_fbc[0];
	XFree(tmp_fbc);
}
