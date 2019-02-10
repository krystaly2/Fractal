/*
 * Bitmap.cpp
 *
 *  Created on: Jan 27, 2019
 *      Author: krystal.yang
 */

#include <fstream>
#include "Bitmap.h"


using namespace std;
using namespace caveOfProgramming;


namespace caveOfProgramming {

Bitmap::Bitmap(){

}

Bitmap::Bitmap(int width, int height):m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}) {
	pixelsSize = m_width*m_height*3; // 3: rgb
}


void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){
	uint8_t* pPixel = m_pPixels.get();

	pPixel += (y*3)*m_width + (x*3); // move the ptr to correct (x,y) position

	// store rgb in reverse order since it's little Endian
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;

}


bool Bitmap::write(string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + pixelsSize;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;
	file.open(filename, ios::out|ios::binary);

	if(!file){
		return false;
	}

	file.write((char*)&fileHeader, sizeof(fileHeader));
	file.write((char*)&infoHeader, sizeof(infoHeader));
	file.write((char*)m_pPixels.get(), pixelsSize); //unique ptr can't be casted to char* directly so use get()


	file.close();

	if(!file){
		return false;
	}


	return false;
}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace caveOfProgramming */
