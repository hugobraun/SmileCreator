//
//  Transformation.cpp
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#include "Transformation.h"

using namespace std;
using namespace cv;

void rotate(Mat& src, double angle, Mat& dst)
{
    int len = std::max(src.cols, src.rows);
    Point2f pt(len/2., len/2.);
    Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);
    
    warpAffine(src, dst, r, Size(len, len));
}

void resizeWithRatio(Mat& src, double maxwidth, Mat& dst)
{
    double ratio = maxwidth / src.cols;
    
    Size size(maxwidth,src.rows * ratio);
    resize(src,dst,size);
}

Point2f multiplyMatrixAndVector(Mat& M, Point2f p) {
    Point2f r;

    r.x = M.at<double>(0,0)*p.x + M.at<double>(0,1)*p.y + M.at<double>(0,2);
    r.y = M.at<double>(1,0)*p.x + M.at<double>(1,1)*p.y + M.at<double>(1,2);
    
    return r;
}