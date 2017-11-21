#ifndef __FRAME_FUNCTION__
#define __FRAME_FUNCTION__

#include "opencv2/opencv.hpp"

#include "hw2.h"
#include "context.h"
#include <stdint.h>
#include <vector>

using namespace cv;
using namespace std;


void frame_function(Context &context, Scalar colour, Mat &mat, BackgroundSubtractorMOG2 &background, Point *oldMP);

#endif
