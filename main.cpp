#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "Picture.h"

#define PI 3.14


using namespace std;
using namespace cv;


int main( int argc, const char** argv )
{
    PictureFaceSet pfs;
    
    Picture picture1("pictures/6.jpg", pfs);
    pfs.resetWithSize(picture1.getRows(), picture1.getCols());
    
    picture1.generatePictureFaceSet();
    
    picture1.drawComputedFaces();
    
    picture1.showAndWait();
    

    return 0;
}
