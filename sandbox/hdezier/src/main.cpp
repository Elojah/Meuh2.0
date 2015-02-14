/*
* @Author: Latias
* @Date:   2015-02-13 10:41:52
* @Last Modified by:   Latias
* @Last Modified time: 2015-02-13 10:50:54
*/

#include "X11Win.hpp"
#include "SimpleTriangle.hpp"

int main(void) {
	X11Win			win(800, 600);
	SimpleTriangle	t;

	win.init();
	t.draw();
	win.loop();
	return (0);
}
