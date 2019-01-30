/*
 * Mandelbrot.h
 *
 *  Created on: Jan 30, 2019
 *      Author: krystal.yang
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace caveOfProgramming {

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 1000;
public:
	Mandelbrot();
	virtual ~Mandelbrot();
	static int getIterations(double x, double y);
};

} /* namespace caveOfProgramming */

#endif /* MANDELBROT_H_ */
