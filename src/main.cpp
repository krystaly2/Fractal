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

#include "FractalCreator.h"

using namespace std;
using namespace caveOfProgramming;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 600;
	FractalCreator fractalCreator(WIDTH, HEIGHT);

	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(255, 0, 0));
	fractalCreator.addRange(0.5, RGB(255, 255, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	fractalCreator.addZoom(295, HEIGHT - 202, 0.1);
	fractalCreator.addZoom(312, HEIGHT - 304, 0.1);

	fractalCreator.run("test.bmp");

	cout << "hi girls morning" << endl;
}

