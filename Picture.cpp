//
//  Picture.cpp
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#include "Picture.h"
#include "Transformation.h"

String face_cascade_name = "data/haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;


Picture::Picture(Mat& img, PictureFaceSet& pfs) : img(img), pfs(pfs)
{}

Picture::Picture(string filename, PictureFaceSet& pfs) : pfs(pfs)
{
    img = imread(filename);
}

void Picture::drawComputedFaces()
{
    drawFaces(pfs.getFaces());
}

void Picture::drawFaceWithAngle(double angle)
{
    vector<PictureFace> faces = getFacesWithAngle(angle);
    this->drawFaces(faces);
}

void Picture::drawFaces(const vector<PictureFace>& faces) {
    for( size_t i = 0; i < faces.size(); i++ )
    {
        PictureFace pf = faces[i];
        
        vector<Point> polygon = pf.getROI();
        
        int n = polygon.size();
        for( size_t j = 0; j < n; j++ )
        {
            int qpu = (j+1)%n;
            
            line(img, polygon[j], polygon[qpu], Scalar(255,0,255),3);
        }
        
        circle(img, pf.getCenter(), 10, Scalar(255,0,0), 5);
    }
}

vector<PictureFace> Picture::getFacesWithAngle(double angle)
{
    if(!face_cascade.load(face_cascade_name)){
        cout << "Error while loading face xml file. Exiting" << endl;
        exit(-1);
    };

    vector<Rect> faces;
    Mat imggray;
    Mat thumbnail;
    
    cvtColor(img, imggray, CV_BGR2GRAY);
    equalizeHist(imggray, imggray);
    
    //Turning image
    
    int len = max(img.cols, img.rows);
    Point2f pt(len/2., len/2.);
    Mat dst(len,len,DataType<float>::type);
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    
    warpAffine(img, dst, r, Size(len, len));
    
    
     //Detecting faces
    face_cascade.detectMultiScale(dst, faces, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
    
    vector<PictureFace> listpfaces;
    
    Mat rt = getRotationMatrix2D(pt, -angle, 1.0);
    
    
    for( size_t i = 0; i < faces.size(); i++ )
    {
        Mat faceROI = dst(faces[i]);
        Rect f = faces[i];
        Point2f p1t(f.x, f.y);
        Point2f p2t(f.x + f.width, f.y);
        Point2f p3t(f.x + f.width, f.y + f.height);
        Point2f p4t(f.x, f.y + f.height);
        
        vector<Point> polygon;
        Point p1;
       
        
        
        polygon.push_back(multiplyMatrixAndVector(rt, p1t));
        polygon.push_back(multiplyMatrixAndVector(rt, p2t));
        polygon.push_back(multiplyMatrixAndVector(rt, p3t));
        polygon.push_back(multiplyMatrixAndVector(rt, p4t));
        
        
        Point centert(f.x + f.width/2, f.y + f.height/2);
        Point center = multiplyMatrixAndVector(rt, centert);
        
        Face fa(faceROI);
        
        PictureFace pface(fa, center, polygon, img);
        
        listpfaces.push_back(pface);
    }
    
    return listpfaces;
}

void Picture::generatePictureFaceSet() {
    for(int i = 0; i<=60; i+=10) {
            vector<PictureFace> faces = getFacesWithAngle(i);
        
            for( size_t i = 0; i < faces.size(); i++ )
            {
                pfs.addPictureFace(faces[i]);
            }
        
            cout << "Angle " << i << " done" << endl;
    }
    
    for(int i = -10; i>=-60; i-=10) {
        vector<PictureFace> faces = getFacesWithAngle(i);
        
        for( size_t i = 0; i < faces.size(); i++ )
        {
            pfs.addPictureFace(faces[i]);
        }
        
        cout << "Angle " << i << " done" << endl;
    }
    
}


void Picture::showAndWait() {
    this->show();
    waitKey();
}

int Picture::getCols()  {
    return img.cols;
}

int Picture::getRows()  {
    return img.rows;
}

void Picture::show() {
    Mat thumbnail;
    resizeWithRatio(img, 1000, thumbnail);
    imshow("Image", thumbnail);
}
