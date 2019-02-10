/*
 * FractalCreator.h
 *
 *  Created on: Feb 7, 2019
 *      Author: krystal.yang
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <math.h>
#include "Zoom.h"
#include "ZoomList.h"
#include "Mandelbrot.h"
#include "Bitmap.h"

using namespace std;

namespace caveOfProgramming {

class FractalCreator {
private:
	int width;
	int height;
	int total { 0 }; // total: number of pixels with iterations from 0 to MAX_ITERATIONS-1
	Bitmap bitmap;
	ZoomList zoomList;

	// histogram: counts the number of pixels with each iteration
	// iterations as index, range from 0 to MAX_ITERATIONS-1
	unique_ptr<int[]> histogram;

	// fractal: stores number of iterations for each pixel
	unique_ptr<int[]> fractal;

	string bitmapName;

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void addZoom(const int zoomWidth, const int zoomHeight,
			const double zoomScale);
	void setBitmapName(string name);
	void drawBitmap();
	void drawBitmap(string fileName);

	void calculateIterations();
	void drawFractal();
	void writeBitmap(string name);

};

} /* namespace caveOfProgramming */

#endif /* FRACTALCREATOR_H_ */
