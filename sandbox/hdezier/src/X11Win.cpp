#include "X11Win.hpp"
#include <iostream>

X11Win::X11Win(void) {
}

X11Win::X11Win(std::size_t width, std::size_t height) :
															_width(width),
															_height(height)
{
	if (!(_d = XOpenDisplay(NULL))) {
		std::cout << "Error: Display environment variable is wrong" << std::endl;
		return ;
	}
	_root = XDefaultRootWindow(_d);
	_screen = XDefaultScreen(_d);
	_v = XDefaultVisual(_d, _screen);
}

X11Win::~X11Win(void) {
}

void		X11Win::init(void) {

	/*Window XCreateWindow(
	display, parent, x, y, width, height, border_width, depth,
		class, visual, valuemask, attributes)*/
	_w =  XCreateWindow(_d
						, _root
						, 0
						, 0
						, _width
						, _height
						, 0
						, XDefaultDepth(_d, _screen)
						, 1
						, _v
						, 0
						, NULL);
	XMapWindow(_d, _w);
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
void		X11Win::loop(void) {
	while (true) {
		XNextEvent(_d, &_e);
	}
}
