/*
 * BitmapFileHeader.h
 *
 *  Created on: Jan 26, 2019
 *      Author: krystal.yang
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

//#include <cstdint>

struct BitmapFileHeader {
	char header[2]{'B', 'M'};
};

#endif /* BITMAPFILEHEADER_H_ */
