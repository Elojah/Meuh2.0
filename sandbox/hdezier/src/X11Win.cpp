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
}

X11Win::~X11Win(void) {
	glXMakeCurrent(_d, 0, 0);
	glXDestroyContext(_d, _ctx);
	XDestroyWindow(_d, _w);
	XFreeColormap(_d, _cmap);
	XCloseDisplay(_d);
}

void		X11Win::init(void) {
	glXCreateContextAttribsARBProc	glXCreateContextAttribsARB;
	XSetWindowAttributes				swa;
	XVisualInfo							*vi;

	static int				context_attribs[] = {
		GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
		GLX_CONTEXT_MINOR_VERSION_ARB, 0,
		//GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		None
	};

	assignBestFBC();
	vi = glXGetVisualFromFBConfig(_d, _fbc);
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
	_glxWin = glXCreateWindow(_d, _fbc, _w, NULL);
	XFree(vi);
	XStoreName(_d, _w, "GL Window");
	XMapWindow(_d, _w);

	glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)glXGetProcAddressARB(
		(const GLubyte *)"glXCreateContextAttribsARB");
	_ctx = glXCreateContextAttribsARB(_d, _fbc, 0, True, context_attribs);
	XSync(_d, False);
	glXMakeCurrent(_d, _glxWin, _ctx);
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
	glClearColor(0, 0.5, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glXSwapBuffers(_d, _glxWin);
	while (true) {

		glClear(GL_COLOR_BUFFER_BIT);
		for (std::vector<IObject>::iterator it = objects.begin(); it != objects.end(); ++it) {
			it->loop();
		}

		XNextEvent(_d, &_e);
		if (_e.xkey.keycode == 24) {/*A*/
			glXSwapBuffers(_d, _glxWin);
		}
		else if (_e.xkey.keycode == 9) {/*ESC*/
			break ;
		}
	}
}

void		X11Win::assignBestFBC(void) {
	GLXFBConfig		*tmp_fbc;
	XVisualInfo			*vi;
	int					fbcount;
	int					best_fbc, worst_fbc, best_num_samp, worst_num_samp;
	int					samp_buf, samples;
	static int			_v_att[] = {
		GLX_X_RENDERABLE, True,
		GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
		GLX_RENDER_TYPE, GLX_RGBA_BIT,
		GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
		GLX_RED_SIZE, 8,
		GLX_GREEN_SIZE, 8,
		GLX_BLUE_SIZE, 8,
		GLX_ALPHA_SIZE, 8,
		GLX_DEPTH_SIZE, 24,
		GLX_STENCIL_SIZE, 8,
		GLX_DOUBLEBUFFER, True,
		// GLX_SAMPLE_BUFFERS , 1,
		// GLX_SAMPLES, 4,
		None
	};

	tmp_fbc = glXChooseFBConfig(_d, DefaultScreen(_d), _v_att, &fbcount);
	best_fbc = worst_fbc = best_num_samp = -1;
	worst_num_samp = 999;

	for (int i = 0; i < fbcount; ++i) {
		if ((vi = glXGetVisualFromFBConfig(_d, tmp_fbc[i]))) {
			glXGetFBConfigAttrib(_d, tmp_fbc[i], GLX_SAMPLE_BUFFERS, &samp_buf);
			glXGetFBConfigAttrib(_d, tmp_fbc[i], GLX_SAMPLES, &samples);
			if (best_fbc < 0 || (samp_buf && samples > best_num_samp)) {
				best_fbc = i;
				best_num_samp = samples;
			}
			if (worst_fbc < 0 || !samp_buf || samples < worst_num_samp) {
				worst_fbc = i;
				worst_num_samp = samples;
			}
		}
		XFree(vi);
	}
	_fbc = tmp_fbc[best_fbc];
	XFree(tmp_fbc);
}
