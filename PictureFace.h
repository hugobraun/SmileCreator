//
//  PictureFace.h
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#ifndef __Project__PictureFace__
#define __Project__PictureFace__

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "Face.h"

class Picture;

class PictureFace {
private:
    Face face;
    Point center;
    vector<Point> roi;
    int score;
    Mat img;
public:
    PictureFace(Face& face, Point& center, vector<Point>& polygonROI, Mat& img);
    ~PictureFace();
    bool isEquivalentTo(PictureFace& other);
    bool hasHigherScoreThan(PictureFace& other);
    vector<Point> getROI();
    Point getCenter();
    Face getFace();
    int getScore();
    Mat getImg(); //should be regenerated at that point
};
#endif /* defined(__Project__PictureFace__) */
