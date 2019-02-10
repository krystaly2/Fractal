/*
 * FractalCreator.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: krystal.yang
 */

#include <iostream>
#include "FractalCreator.h"

using namespace caveOfProgramming;

namespace caveOfProgramming {

FractalCreator::FractalCreator(int width, int height) :
		width(width), height(height), histogram(
				new int[Mandelbrot::MAX_ITERATIONS] { 0 }), fractal(
				new int[width * height] { 0 }), bitmap(width, height), zoomList(
				width, height) {
	addZoom(width / 2, height / 2, 4.0 / width);
}

void FractalCreator::setBitmapName(string name){
	bitmapName = name;
}

void FractalCreator::drawBitmap() {
	calculateIterations();
	drawFractal();
//	writeBitmap("test.bmp");
	writeBitmap(bitmapName);

}

void FractalCreator::drawBitmap(string fileName) {
	calculateIterations();
	drawFractal();
	writeBitmap(fileName);
}

void FractalCreator::calculateIterations() {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			pair<double, double> coords = zoomList.doZoom(x, y);
			int iterations = Mandelbrot::getIterations(coords.first,
					coords.second);
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}
			fractal[y * width + x] = iterations;

		}
	}

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
		total += histogram[i];
	}
}

void FractalCreator::drawFractal() {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			int iterations = fractal[y * width + x];
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;
				for (int i = 0; i <= iterations; ++i) {
					hue += ((double) histogram[i]) / total;
				}

				green = pow(255, hue); // to make graph more clear
			}

			bitmap.setPixel(x, y, red, green, blue);

		}
	}
}

void FractalCreator::addZoom(const int zoomWidth, const int zoomHeight,
		const double zoomScale) {
	zoomList.add(Zoom(zoomWidth, zoomHeight, zoomScale));
}

void FractalCreator::writeBitmap(string name) {
	bitmap.write(name);
}

FractalCreator::~FractalCreator() {
	// TODO Auto-generated destructor stub
//	delete fractal;
}

} /* namespace caveOfProgramming */
