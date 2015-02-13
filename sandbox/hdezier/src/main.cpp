/*
* @Author: Latias
* @Date:   2015-02-13 10:41:52
* @Last Modified by:   Latias
* @Last Modified time: 2015-02-13 10:50:54
*/

#include "X11Win.hpp"

int main(int argc, char ** argv) {
	X11Win		win(800, 600);

	win.init();
	win.loop();
	(void)argc;
	(void)argv;
	return (0);
}
