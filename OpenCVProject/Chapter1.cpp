#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//
///////////////////  Images  //////////////////////
//
//int main() {
//
//    string path = "Resources/test.png";
//    
//    //Mat is a matrix data type introduced by opencv to handle images.
//    Mat img = imread(path);
//
//    //imshow for showing the image.
//    imshow("Image", img);
//
//    //Image will close as soon as it opens.
//    //So we'll use waitkey to hold it and pass 0 in it to hold image for infinite time until we close it.
//    waitKey(0);
//    return 0;
//
//}

/////////////// Video //////////////////////

//void main() {
//
// string path = "Resources/test_video.mp";
// VideoCapture cap(path);
// Mat img;
//
// while (true) {
//
// cap.read(img);
// imshow("Image", img);
// waitKey(1);
// }
//}

///////////////// Webcam //////////////////////

void main() {

 VideoCapture cap(0);
 Mat img;

 while (true) {

 cap.read(img);
 imshow("Image", img);
 waitKey(1);
 }
}