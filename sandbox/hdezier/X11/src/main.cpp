/*
* @Author: Latias
* @Date:   2015-02-13 10:41:52
* @Last Modified by:   Latias
* @Last Modified time: 2015-02-13 10:50:54
*/

#include <vector>
#include "X11Win.hpp"
#include "Map.hpp"
#include "SimpleTriangle.hpp"

int main(void) {
	X11Win					win(800, 600);
	Camera					cam;
	Map					m;
	SimpleTriangle			t;

	win.init();
	t.init();
	m.addObject(&t);

	win.loop(m, cam);
	return (0);
}
