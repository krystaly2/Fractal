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
#include "include/Bitmap.h"

using namespace std;
using namespace caveOfProgramming;

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH,HEIGHT);

	for(int x = 0; x < WIDTH; ++x) {
		for(int y = 0; y < HEIGHT; ++y){
			bitmap.setPixel(x, y, 255, 0, 0);
		}
	}
//	bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);
	bitmap.write("test.bmp");


	cout << "hi girls morning" << endl;
}

