//
//  Face.h
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#ifndef __Project__Face__
#define __Project__Face__

#include <stdio.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;
using namespace cv;

class Face
{
private:
    Mat& imgface;
public:
    Face(Mat& imgface);
    Mat setFaceUpright();
    vector<Rect> getEyes();
    int getScore();
};

#endif /* defined(__Project__Face__) */


