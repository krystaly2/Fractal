/*
 * BitmapInfoHeader.h
 *
 *  Created on: Jan 27, 2019
 *      Author: krystal.yang
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint> // for int32_t and int16_t

#pragma pack(2)

namespace caveOfProgramming {
struct BitmapInfoHeader {
	int32_t headerSize { 40 }; // sizeof(BitmapInfoHeader)
	int32_t width; // width and height of actual bitmap
	int32_t height;
	int16_t planes { 1 };
	int16_t bitsPerPixel { 24 }; // 3 bytes: r, g, b
	int32_t compression { 0 };
	int32_t dataSize { 0 };
	int32_t horizontalResolution { 2400 };
	int32_t verticalResolution { 2400 };
	int32_t colors { 0 };
	int32_t importantColors { 0 };
};
}

#endif /* BITMAPINFOHEADER_H_ */
