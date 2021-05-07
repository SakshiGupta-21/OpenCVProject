#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////// Color Detection //////////////////////

void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	//finding contours of shapes
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		//find area of ith contour
		int area = contourArea(contours[i]);

		//printing the area of ith contour
		cout << area << endl;

		//string for defining the shape = {Tri, Square, Rect, Circle}
		string objectType;

		if (area > 1000)
		{
			//Calculates a contour perimeter 
			float peri = arcLength(contours[i], true);

			//finding how many points a contour has.
			//store the points in conPoly vector
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			cout << conPoly[i].size() << endl;

			//bound the shape with a rectangle of length = max side of the shape
			boundRect[i] = boundingRect(conPoly[i]);

			//finding the no. of points a contour has.
			int objCor = (int)conPoly[i].size();

			//3 points for triangle
			if (objCor == 3) { objectType = "Tri"; }


			//4 points for rect. or square
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;

				//if aspect ratio is approximately equals to 1 then it's a square
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }

				//otherwise a rectangle
				else { objectType = "Rect"; }
			}

			//if no. of points are greater than 4, it should be a circle
			else if (objCor > 4) { objectType = "Circle"; }

			//draw the contours on the outline of the shapes
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);

			//draw a rectangle to inbox the shape of max. side as length of the rectangle
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

			//put the name of the shape above the rectanglular shape
			putText(img, objectType, { boundRect[i].x,boundRect[i].y-5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}
}

void main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	//imshow(“Image Gray”, imgGray);
	//imshow(“Image Blur”, imgBlur);
	//imshow(“Image Canny”, imgCanny);
	//imshow(“Image Dil”, imgDil);

	waitKey(0);

}