/*
 * ZoomList.h
 *
 *  Created on: Feb 5, 2019
 *      Author: krystal.yang
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility> // for pair
#include "Zoom.h"

using namespace std;

namespace caveOfProgramming {

class ZoomList {
private:
	double m_xCenter{0};
	double m_yCenter{0};
	double m_scale{1.0};

	int m_width{0};
	int m_height{0};

	vector<Zoom> zooms;
public:
	ZoomList();
	ZoomList(int width, int height);

	// zoom in based on current zoom level
	// reset coordinate m_xCenter, m_yCenter and m_scale
	void add(const Zoom& zoom);

	// convert (x,y) from bitmap location to coordinate location based on current zoom
	// bitmap location x ranges from 0 to WIDTH and y ranges from 0 to HEIGHT
	// coordinate location x ranges from -WIDTH/2*scale + m_xCenter to WIDTH/2*scale + m_xCenter
	// and y ranges similarly but based on HEIGHT and m_yCenter
	pair<double, double> doZoom(int x, int y);
};

} /* namespace caveOfProgramming */

#endif /* ZOOMLIST_H_ */
