#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


///////////////////  Color Detection //////////////////////

int main() {

    string path = "Resources/sakshi.jpg";
    
    //Mat is a matrix data type introduced by opencv to handle images.
    Mat img = imread(path);
    Mat imgHSV, mask;

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    int hmin=0, hmax=19, smin=110, smax=240, vmin=153, vmax=255;

    namedWindow("Trackbars", (640, 200));
    createTrackbar("HUE MIN", "Trackbars", &hmin,179);
    createTrackbar("HUE MAX", "Trackbars", &hmax, 179);
    createTrackbar("SAT MIN", "Trackbars", &smin, 255);
    createTrackbar("SAT MAX", "Trackbars", &smax, 255);
    createTrackbar("VALUE MIN", "Trackbars", &vmin, 255);
    createTrackbar("VALUE MAX", "Trackbars", &vmax, 255);


    while (true) {
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);

        //imshow for showing the image.
        imshow("Image", img);
        imshow("Image", imgHSV);
        imshow("Image", mask);

        //Image will close as soon as it opens.
        //So we'll use waitkey to hold it and pass 0 in it to hold image for infinite time until we close it.
        waitKey(1);
    }
    return 0;

}
