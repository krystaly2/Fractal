/*
 * main.cpp
 *
 *  Created on: Jan 26, 2019
 *      Author: krystal.yang
 *
 *  shortcut:
 *  ctrl+f11 run
 *  ctrl+b   build
 */



#include <iostream>
#include <climits>
#include <algorithm>
#include "include/Bitmap.h"
#include "include/Mandelbrot.h"

using namespace std;
using namespace caveOfProgramming;

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH,HEIGHT);

	double minV = 255;
	double maxV = 0;

	for(int x = 0; x < WIDTH; ++x) {
		for(int y = 0; y < HEIGHT; ++y){
			double xFractal = (x - WIDTH/2)*2.0/WIDTH;
			double yFractal = (y - HEIGHT/2)*2.0/HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			uint8_t red = (uint8_t)(256*(double)iterations/Mandelbrot::MAX_ITERATIONS);
			bitmap.setPixel(x, y, red, red, red);
		}
	}

//	cout << minV << " " << maxV << endl;
	bitmap.write("test.bmp");


	cout << "hi girls morning" << endl;
}

