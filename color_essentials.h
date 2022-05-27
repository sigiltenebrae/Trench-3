//
// Created by chris on 5/27/2022.
//

#ifndef TRENCH_3_COLOR_ESSENTIALS_H
#define TRENCH_3_COLOR_ESSENTIALS_H
#include <math.h>

#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

// Math
const double pi = 2 * acos(0.0);

// Variables
const Vec3b cl_yellow(0, 255, 255);
const Vec3b cl_yellow_white(127, 255, 255);
const Vec3b cl_white(255, 255, 255);
const Vec3b cl_orange(0, 127, 255);
const Vec3b cl_red_white(127, 127, 255);
const Vec3b cl_magenta_white(255, 127, 255);
const Vec3b cl_red(0, 0, 255);
const Vec3b cl_red_magenta(127, 0, 255);
const Vec3b cl_magenta(255, 0, 255);
const Vec3b cl_yellow_green(0, 255, 127);
const Vec3b cl_green_white(127, 255, 127);
const Vec3b cl_cyan_white(255, 255, 127);
const Vec3b cl_yellow_black(0, 127, 127);
const Vec3b cl_gray(127, 127, 127);
const Vec3b cl_blue_white(255, 127, 127);
const Vec3b cl_red_black(0, 0, 127);
const Vec3b cl_magenta_black(127, 0, 127);
const Vec3b cl_blue_magenta(255, 0, 127);
const Vec3b cl_green(0, 255, 0);
const Vec3b cl_green_cyan(127, 255, 0);
const Vec3b cl_cyan(255, 255, 0);
const Vec3b cl_green_black(0, 127, 0);
const Vec3b cl_blue_green(127, 127, 0);
const Vec3b cl_azure(255, 127, 0);
const Vec3b cl_black(0, 0, 0);
const Vec3b cl_blue_black(127, 0, 0);
const Vec3b cl_blue(255, 0, 0);


/* functions */
Mat neon_glow(Mat image, int gaus);
Mat neon_icon(Mat image);
Mat gradient(Mat image, double angle);
#endif //TRENCH_3_COLOR_ESSENTIALS_H
