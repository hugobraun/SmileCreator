//
//  Face.cpp
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#include "Face.h"
#include "Transformation.h"

String eyes_cascade_name = "data/haarcascade_eye_tree_eyeglasses.xml";

CascadeClassifier eyes_cascade;

Face::Face(Mat& imgface) : imgface(imgface)
{}

Mat Face::setFaceUpright() {
    Mat dst;
    
    vector<Rect> eyes = getEyes();
    
    double angle = 0;
    
    if(eyes.size() == 2) {
        Mat faceupright;
        
        Point eye1(eyes[0].x + eyes[0].width/2, eyes[0].y + eyes[0].height /2);
        Point eye2(eyes[1].x + eyes[1].width/2, eyes[1].y + eyes[1].height /2);
        double tan = ((double)eye2.y - (double)eye1.y) / ((double)eye2.x - (double)eye1.x);
        angle = atan(tan) / PI * 180;
    }
    
   
    
    rotate(imgface, angle, dst);
    
    return dst;
}

int Face::getScore() {
    
}

vector<Rect> Face::getEyes() {
    if( !eyes_cascade.load( eyes_cascade_name ) ){
        cout << "--(!)Error loading eyes xml file.\n " << endl;
        exit(-1);
    };
    
    vector<Rect> eyes;
    
    eyes_cascade.detectMultiScale(imgface, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
    
    return eyes;
}
