#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

int main() {

    string path = "Resources/Myim.jpg";
    
    //Mat is a matrix data type introduced by opencv to handle images.
    Mat img = imread(path);


    CascadeClassifier faceCascade;

    //we have already trained model for front face detection
    //we'll load that model 
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");

    //if cascade file not loaded properly then it should show as not loaded
    if (faceCascade.empty()) {
        cout << "XML not loaded\n";
    }

    //vector of rect to store points enclosing face
    vector<Rect> faces;

    //function for detecting objects inside the images
    //returned as a list of rectangles.
    faceCascade.detectMultiScale(img, faces, 1.1, 10);
    
    for (int i = 0; i < faces.size(); i++) {
        //add rectangle on Face
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 5);
    }



    //imshow for showing the image.
    imshow("Image", img);

    //Image will close as soon as it opens.
    //So we'll use waitkey to hold it and pass 0 in it to hold image for infinite time until we close it.
    waitKey(0);
    return 0;

}