//
//  Transformation.h
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#ifndef __Project__Transformation__
#define __Project__Transformation__

#include <stdio.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include <iostream>
#include <stdio.h>
#include <unistd.h>
#define PI 3.14

using namespace std;
using namespace cv;

#endif /* defined(__Project__Transformation__) */

void rotate(Mat& src, double angle, Mat& dst);
void resizeWithRatio(Mat& src, double maxwidth, Mat& dst);
Point2f multiplyMatrixAndVector(Mat& M, Point2f r) ;