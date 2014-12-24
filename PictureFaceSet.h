//
//  PictureFaceSet.h
//  Project
//
//  Created by Hugo BRAUN on 18/11/2014.
//
//

#ifndef __Project__PictureFaceSet__
#define __Project__PictureFaceSet__

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "PictureFace.h"

class PictureFaceSet {
private:
    vector<PictureFace> faces;
    Mat* facescenters;
    int rows;
    int cols;
public:
    PictureFaceSet(int rows, int cols);
    PictureFaceSet();
    void addPictureFace(PictureFace face);
    vector<PictureFace> getFaces();
    void resetWithSize(int rows, int cols);
};

#endif /* defined(__Project__PictureFaceSet__) */
