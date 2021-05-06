#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////////  Resize and Crop  //////////////////////

int main() {

    string path = "Resources/test.png";

    //Mat is a matrix data type introduced by opencv to handle images.
    Mat img = imread(path);

    Mat imgResize;


    //cout << img.size() << endl;

    //to resize in a specific size
    //resize(img, imgResize, Size(300, 200));

    //to scale it as half the size
    resize(img, imgResize, Size(),0.5,0.5);

    //imshow for showing original image.
    imshow("Image", img);


    Rect roi(200, 100, 300, 300);

    Mat imgCrop;

    imgCrop = img(roi);


    //imshow for showing the resized image.
    imshow("Image", imgResize);

    //imshow for showing the cropped image.
    imshow("Image", imgCrop);

    //Image will close as soon as it opens.
    //So we'll use waitkey to hold it and pass 0 in it to hold image for infinite time until we close it.
    waitKey(0);
    return 0;

}
