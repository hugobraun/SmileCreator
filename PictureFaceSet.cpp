//
//  PictureFaceSet.cpp
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#include "PictureFaceSet.h"

//distance equivalence
int dmax = 25;

PictureFaceSet::PictureFaceSet(int rows, int cols) : rows(rows), cols(cols)
{
    facescenters = new Mat(rows, cols, CV_16S, -1);
}

PictureFaceSet::PictureFaceSet() : rows(0), cols(0)
{
    facescenters = new Mat(rows, cols, CV_16S, -1);
}

void PictureFaceSet::resetWithSize(int r, int c) {
    rows = r;
    cols = c;
    facescenters = new Mat(rows, cols, CV_16S, -1);
}


void PictureFaceSet::addPictureFace(PictureFace face) //should be reference
{
    Point center = face.getCenter();
    
    int index = -1;
    
    if(center.x > cols)
        return;
    
    if(center.y > rows)
        return;
    
    int jmax = min(rows, center.y + dmax);
    int imax = min(cols, center.x + dmax);
    
    for (int i = max(center.x - dmax,0); i<=imax; i++) {
        for (int j = max(center.y - dmax,0); j<=jmax; j++) {
            short pi = facescenters->at<short>(j,i);
            if(pi != -1) {
                index = pi;
                facescenters->at<short>(center.y, center.x) = index;
                return;
            }
        }
    }
    
    faces.push_back(face);
    facescenters->at<short>(center.y, center.x) = faces.size() - 1;
}

vector<PictureFace> PictureFaceSet::getFaces() {
    return faces;
}