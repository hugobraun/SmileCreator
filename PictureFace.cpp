//
//  PictureFace.cpp
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#include "PictureFace.h"

PictureFace::PictureFace(Face& face, Point& center, vector<Point>& polygonROI, Mat& img) : face(face), center(center), roi(polygonROI), score(1), img(img)
{}


vector<Point> PictureFace::getROI() {
    return roi;
}

Point PictureFace::getCenter() {
    return center;
}

Face PictureFace::getFace() {
    return face;
}

int PictureFace::getScore() {
    return score;
}

Mat PictureFace::getImg() {
    return img;
}

PictureFace::~PictureFace()
{

}