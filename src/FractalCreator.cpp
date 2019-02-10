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


void FractalCreator::addRange(double rangeEnd, const RGB& rgb) {
	ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	colors.push_back(rgb);

	if (bGotFirstRange) {
		rangeTotals.push_back(0);
	}

	bGotFirstRange = true;
}

void FractalCreator::addZoom(const int zoomWidth, const int zoomHeight,
		const double zoomScale) {
	zoomList.add(Zoom(zoomWidth, zoomHeight, zoomScale));
}

void FractalCreator::run(string name) {
	calculateIterations();
	calculateRangeTotals();
	drawFractal();
	writeBitmap(name);
}


FractalCreator::FractalCreator(int width, int height) :
		width(width), height(height), histogram(
				new int[Mandelbrot::MAX_ITERATIONS] { 0 }), fractal(
				new int[width * height] { 0 }), bitmap(width, height), zoomList(
				width, height) {
	addZoom(width / 2, height / 2, 4.0 / width); // initialize the zoom level
}


void FractalCreator::calculateRangeTotals() {
	int rangeIndex = 0;

	for(int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i){
		int pixels = histogram[i];

		if(i == ranges[rangeIndex+1]){
			rangeIndex ++;
		}

		rangeTotals[rangeIndex] += pixels;
	}

	for (auto value : rangeTotals) {
		cout << "Range total: " << value << endl;
	}
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
	RGB startColor(0, 0, 0); // black
	RGB endColor(123, 255, 234);
	RGB diffColor = endColor - startColor;

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

				red = startColor.r + diffColor.r * hue;
				green = startColor.g + diffColor.g * hue;
				blue = startColor.b + diffColor.b * hue;

			}

			bitmap.setPixel(x, y, red, green, blue);

		}
	}
}

void FractalCreator::writeBitmap(string name) {
	bitmap.write(name);
}

FractalCreator::~FractalCreator() {
	// TODO Auto-generated destructor stub
//	delete fractal;
}

} /* namespace caveOfProgramming */
