#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat img = imread(argv[1], 0);
    if(img.empty())
    {
        cout << "can not open image"<< endl;
        return -1;
    }

    Mat fn, cfn;
    Canny(img, fn, 50, 200, 3);
    cvtColor(fn, cfn, COLOR_GRAY2BGR);

#if 0
    vector<Vec2f> lines;
    HoughLines(fn, lines, 1, CV_PI/180, 100, 0, 0 );
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line( cfn, pt1, pt2, Scalar(0,0,255), 1, CV_AA);
    }

#else
    vector<Vec4i> lines;
    HoughLinesP(fn, lines, 1, CV_PI/180, 50, 50, 10 );
    for( size_t i = 0; i < lines.size(); i++ )
    {
        Vec4i l = lines[i];
        line( cfn, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 1, LINE_AA);
    }
#endif
    imshow("source", img);
	waitKey(0);
    imshow("detected lines", cfn);
    waitKey(0);
    return 0;
}

