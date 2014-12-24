//
//  Picture.h
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#ifndef __Project__Picture__
#define __Project__Picture__

#include <stdio.h>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "Face.h"
#include "PictureFace.h"
#include "PictureFaceSet.h"

using namespace std;
using namespace cv;

class Picture {
private:
    Mat img;
    PictureFaceSet& pfs;
    void drawFaces(const vector<PictureFace>& faces);
public:
    Picture(Mat& img, PictureFaceSet& pfs);
    Picture(string filename, PictureFaceSet& pfs);
    vector<PictureFace> getFacesWithAngle(double angle);
    vector<PictureFace> getAllFaces();
    void generatePictureFaceSet();
    void drawComputedFaces();
    void drawFaceWithAngle(double angle);
    void showAndWait();
    void show();
    int getCols();
    int getRows();
};

#endif /* defined(__Project__Picture__) */
