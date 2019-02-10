/*
 * ZoomList.cpp
 *
 *  Created on: Feb 5, 2019
 *      Author: krystal.yang
 */
#include <iostream>
#include "ZoomList.h"

using namespace std;

namespace caveOfProgramming {

ZoomList::ZoomList(){

}

ZoomList::ZoomList(int width, int height):m_width(width), m_height(height){

	// TODO Auto-generated constructor stub

}


void ZoomList::add(const Zoom& zoom){
	zooms.push_back(zoom);

	m_xCenter += (zoom.x - m_width/2)*m_scale;
	m_yCenter += (zoom.y - m_height/2)*m_scale;
	m_scale *= zoom.scale;
//	cout << m_xCenter << ", " << m_yCenter << ", " << m_scale << endl;

}

pair<double, double> ZoomList::doZoom(int x, int y){
	double xFractal = (x - m_width/2)*m_scale + m_xCenter;
	double yFractal = (y - m_height/2)*m_scale + m_yCenter;

	/*
	 * explanation:
	 * if x == m_width/2 and y == m_height/2, which means (x,y) is the center pixel
	 * xFractal = m_xCenter and yFractal = m_yCenter
	 * otherwise, scale x and y accordingly and see how far it is from (m_xCenter, m_yCenter)
	 *
	 * */

	return pair<double,double>(xFractal,yFractal);
}



} /* namespace caveOfProgramming */
