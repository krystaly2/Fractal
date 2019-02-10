/*
 * BitmapFileHeader.h
 *
 *  Created on: Jan 26, 2019
 *      Author: krystal.yang
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint> // make sure int is 32 bits
#pragma pack(2) // data alignment to 2 bytes

namespace caveOfProgramming {
struct BitmapFileHeader {
	char header[2] { 'B', 'M' }; // 1 char is 1 byte
	int32_t fileSize;
	int32_t reserved { 0 }; // initialzie to zero
	int32_t dataOffset; // how long into the file the actual data begins

};
}

#endif /* BITMAPFILEHEADER_H_ */
