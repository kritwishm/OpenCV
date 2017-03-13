#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat img1 = imread(argv[1], 1);
    if(img1.empty())
    {
        cout << "can not open image" << endl;
        return -1;
    }
    Mat img2;
    cvtColor(img1, img2, COLOR_BGR2GRAY);
    medianBlur(img2, img2, 5);
    vector<Vec3f> circles;
    HoughCircles(img2, circles, HOUGH_GRADIENT, 1,img2.rows/16, 100, 30, 1, 30 );
    for( size_t i = 0; i < circles.size(); i++ )
    {
        Vec3i c = circles[i];
        circle( img1, Point(c[0], c[1]), c[2], Scalar(0,0,255), 3, LINE_AA);
        circle( img1, Point(c[0], c[1]), 2, Scalar(0,255,0), 3, LINE_AA);
    }
    namedWindow("detected circles", CV_WINDOW_AUTOSIZE);
    imshow("detected circles", img1);
    waitKey();
    return 0;
}
