#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////////  basic Function  //////////////////////

int main() {

    string path = "Resources/test.png";
    
    //Mat is a matrix data type introduced by opencv to handle images.
    Mat img = imread(path);

    Mat imgGray,imgBlur,imgCanny,imgDil;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
    Canny(img, imgCanny, 100, 150);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    dilate(imgCanny, imgDil, kernel);



    //imshow for showing the image.
    imshow("Image", img);

    //imshow for showing the gray image.
    imshow("Image", imgGray);

    //imshow for showing the blur image.
    imshow("Image", imgBlur);

    //imshow for showing the edge of the image/ canny image.
    imshow("Image", imgCanny);

    //imshow for showing the edge of the image/ canny image.
 
    imshow("Image Dilate", imgDil);

    //Image will close as soon as it opens.
    //So we'll use waitkey to hold it and pass 0 in it to hold image for infinite time until we close it.
    waitKey(0);
    return 0;

}
