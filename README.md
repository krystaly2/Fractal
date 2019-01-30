# Fractal
followed tutorial on: https://github.com/caveofprogramming/advanced-cplusplus/wiki/Learn-Advanced-C-Plus-Plus-Tutorial#a-project-drawing-fractal-images
writes fractal image to a bitmap

Mandelbrot:
f(z) = z^2 + c; // c is a complex number
set c to a number, then iterate from z = 0.
if f(z) goes to infinity --> blows up! --> not in mandelbrot set
if f(z) stays bounded near zero --> no blow up --> in mandelbrot set

ex. c = 1
f(0) = 1
f(1) = 2
f(2) = 5
f(5) = 26
...
goes to infinity, blows up!

ex. c = -1
f(0) = -1
f(-1) = 0
stops here, doesn't blow up!

For a Mandelbrot image, we need to color the blow up region with one color, then the non-blow-up region with another color.


