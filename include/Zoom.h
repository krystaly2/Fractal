/*
 * Zoom.h
 *
 *  Created on: Feb 5, 2019
 *      Author: krystal.yang
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace caveOfProgramming {

struct Zoom {
	int x { 0 };
	int y { 0 };
	double scale { 0.0 };

	Zoom(int x, int y, double scale) :
			x(x), y(y), scale(scale) {};
};

} /* namespace caveOfProgramming */

#endif /* ZOOM_H_ */
