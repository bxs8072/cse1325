#include "mandelbrot.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    int width = std::atoi(argv[1]);
    int height = std::atoi(argv[2]);
    int icount = std::atoi(argv[3]);
    int nthreads = std::atoi(argv[4]);

    assert(width >= 0 && height >= 0 && icount >= 0 && nthreads > 0);

    std::string filename = "image.ppm";

    std::ofstream ofs{filename};

    Mandelbrot mandelbrot{width, height, icount, nthreads};

    std::cout << std::endl
              << "\twidth: " << width
              << "\theight: " << height
              << "\ticount: " << icount
              << "\tthreads: " << nthreads
              << std::endl;

    std::cout << "\twrote: " << filename << std::endl;

    ofs << mandelbrot;

    return 0;
}
