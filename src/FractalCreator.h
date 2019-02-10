/*
 * FractalCreator.h
 *
 *  Created on: Feb 7, 2019
 *      Author: krystal.yang
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <iostream>
#include <algorithm>
//#include <math.h>
#include <vector>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"


using namespace std;

namespace caveOfProgramming {

class FractalCreator {
private:
	int width;
	int height;
	int total { 0 }; // total: number of pixels with iterations from 0 to MAX_ITERATIONS-1
	Bitmap bitmap;
	ZoomList zoomList;
	vector<int> ranges;
	vector<int> rangeTotals;
	vector<RGB> colors;
	bool bGotFirstRange{false};

	// histogram: counts the number of pixels with each iteration
	// iterations as index, range from 0 to MAX_ITERATIONS-1
	unique_ptr<int[]> histogram;

	// fractal: stores number of iterations for each pixel
	unique_ptr<int[]> fractal;


	// calcualte number of iterations each (x,y) coordinate takes
	// fill up histogram and fractal
	void calculateIterations();

	void calculateRangeTotals();

	// specify RGB color to draw each pixel based on histrogram
	void drawFractal();

	void writeBitmap(string name);


public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
	void run(string name);
	void addRange(double rangeEnd, const RGB& rgb);
	void addZoom(const int zoomWidth, const int zoomHeight,
						const double zoomScale);

};

} /* namespace caveOfProgramming */

#endif /* FRACTALCREATOR_H_ */
