/*
 * Bitmap.h
 *
 *  Created on: Jan 27, 2019
 *      Author: krystal.yang
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

using namespace std;

namespace caveOfProgramming {

class Bitmap {
private:
	int m_width{0};
	int m_height{0};
	unique_ptr<uint8_t[]> m_pPixel{nullptr};

public:
	Bitmap(int width, int height);

	// set rgb color at that pixel location (x, y)
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

	bool write(string filename);
	virtual ~Bitmap();
};

} /* namespace caveOfProgramming */

#endif /* BITMAP_H_ */
