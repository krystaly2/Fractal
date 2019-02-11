/*
 * FractalCreator.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: krystal.yang
 */

#include <iostream>
#include "assert.h"
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

int FractalCreator::getRange(int iterations) const {
	if (ranges.size() == 0)
		return -1; // error

	if (iterations >= 0 && iterations <= ranges[0])
		return 0;
	for (unsigned i = 0; i < ranges.size() - 1; ++i) {
		if (iterations > ranges[i] && iterations <= ranges[i + 1]) {
			return i;
		}
	}

	return -1; // error
}

void FractalCreator::calculateRangeTotals() {
	int rangeIndex = 0;

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
		int pixels = histogram[i];

		if (i == ranges[rangeIndex + 1]) {
			rangeIndex++;
		}

		rangeTotals[rangeIndex] += pixels;
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

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			int iterations = fractal[y * width + x];
			int range = getRange(iterations);
			assert(range != -1);
			int rangeTotal = rangeTotals[range]; // total number of pixels in range
			int rangeStart = ranges[range];	// the start number of iterations for that range

			RGB& startColor = colors[range]; // use reference here since there is operator= for RGB
			RGB& endColor = colors[range + 1];
			RGB colorDiff = endColor - startColor;

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				int totalPixels = 0;
				for (int i = rangeStart; i <= iterations; ++i) {
					totalPixels += histogram[i];
				}

				// hue is colorDiff * totalPixels/rangeTotal
				red = startColor.r
						+ colorDiff.r * (double) totalPixels / rangeTotal;
				green = startColor.g
						+ colorDiff.g * (double) totalPixels / rangeTotal;
				blue = startColor.b
						+ colorDiff.b * (double) totalPixels / rangeTotal;

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
