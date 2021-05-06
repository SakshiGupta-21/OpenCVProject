#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////////  Shape formation  //////////////////////

int main() {

    

    Mat img(512,512,CV_8UC3,Scalar(255,255,255));

    //thickness=7
    //circle(img, Point(256, 256), 200, Scalar(0, 78, 56), 7);

    //filled circle
    circle(img, Point(256, 256), 200, Scalar(0, 0, 255), FILLED);

    //add rectangle on image
    rectangle(img, Point(120, 226), Point(392, 286), Scalar(255, 255, 255),FILLED);

    //add line on image
    line(img, Point(120, 296), Point(392, 296), Scalar(255, 255, 2555), 5);

    //add text on image
    putText(img, "Sakshi", Point(215, 260), FONT_ITALIC, 1, Scalar(0, 0, 255), 2);



    imshow("Image with circle", img);

    //Image will close as soon as it opens.
    //So we'll use waitkey to hold it and pass 0 in it to hold image for infinite time until we close it.
    waitKey(0);
    return 0;

}
