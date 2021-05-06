#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////////  Warp Images  //////////////////////

int main() {

    string path = "Resources/cards.jpg";

    float w = 250, h = 350;

    Mat img = imread(path);

    Point2f src[4] = { {529,141},{771,190},{405,395},{674,457} };

    Point2f dest[4] = { {0.0,0.0},{w,0.0},{0.0,h},{w,h} };

    Mat matrix = getPerspectiveTransform(src, dest);

    Mat imgWarp;

    warpPerspective(img, imgWarp, matrix,Point(w,h));


   

    imshow("Image with circle", img);
    imshow("Image Warp", imgWarp);
    //imshow("Image Warp", imgC);

    //Image will close as soon as it opens.
    //So we'll use waitkey to hold it and pass 0 in it to hold image for infinite time until we close it.
    waitKey(0);
    return 0;

}
