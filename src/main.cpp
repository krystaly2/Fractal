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
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"


using namespace std;
using namespace caveOfProgramming;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;
	FractalCreator fractalCreator(WIDTH, HEIGHT);

	fractalCreator.addZoom(295, HEIGHT-202, 0.1);
	fractalCreator.addZoom(312, HEIGHT-202, 0.1);

	string fileName = "test.bmp";
	fractalCreator.setBitmapName(fileName);
	fractalCreator.drawBitmap();


	cout << "hi girls morning" << endl;
}

