/*
 * main.cpp
 *
 *  Created on: Jan 26, 2019
 *      Author: krystal.yang
 *
 *  shortcut:
 *  ctrl+f11     run
 *  ctrl+b       build
 *  ctrl+shift+f autoformat
 */

#include <iostream>
#include <climits>
#include <algorithm>
#include <math.h>
#include "include/Bitmap.h"
#include "include/Mandelbrot.h"

using namespace std;
using namespace caveOfProgramming;

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	// histogram: counts the number of pixels with each iteration
	// iterations as index, range from 0 to MAX_ITERATIONS-1
	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS] { 0 }); // {0}: initialize everything to zero

	// fractal: stores number of iterations for each pixel
	unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT] { 0 });

	// fill up histogram and fractal
	for (int x = 0; x < WIDTH; ++x) {
		for (int y = 0; y < HEIGHT; ++y) {
			double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT; // 200 is to shift the image to the right
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT; // scaling factor is the same: 2.0/HEIGHT

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			if (iterations != Mandelbrot::MAX_ITERATIONS)
				histogram[iterations]++;
			fractal[y * WIDTH + x] = iterations;

		}
	}

	// total: number of pixels with iterations from 0 to MAX_ITERATIONS-1
	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
		total += histogram[i];
	}

	// determine the color for each pixel
	for (int x = 0; x < WIDTH; ++x) {
		for (int y = 0; y < HEIGHT; ++y) {
			int iterations = fractal[y * WIDTH + x];
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0;
				for (int i = 0; i <= iterations; ++i) {
					hue += ((double) histogram[i]) / total;
				}

				green = pow(255, hue);
			}

			bitmap.setPixel(x, y, red, green, blue);

		}
	}

//	cout << minV << " " << maxV << endl;
	bitmap.write("test.bmp");

	cout << "hi girls morning" << endl;
}

