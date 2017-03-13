#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int border_type;

int main(int argc, char** argv){
	Mat img1,img2,fn;
	int top,bottom,right,left;
	int c;
	Scalar value;
	RNG rng(12345);	
	img1=imread(argv[1], 1);
	if(!img1.data)
	{
		cout<<"Could not open image"<<std::endl;
		return -1;
	}
	namedWindow("Display Window", CV_WINDOW_AUTOSIZE);
	imshow("Display Window", img1);
	waitKey(0);
	namedWindow("Border image", CV_WINDOW_AUTOSIZE);
	top=(int)(0.05*img1.rows);
	bottom=(int)(0.05*img1.rows);
	left=(int)(0.05*img1.cols);
	right=(int)(0.05*img1.cols);
	img2=img1;
	imshow("Border image",img2);
	while( true )
	{
		c = waitKey(500);
		if( (char)c == 27 )
			{ break; }
		else if( (char)c =='c')
			{ border_type = BORDER_CONSTANT; }
		else if( (char)c == 'r')
			{ border_type = BORDER_REPLICATE; }
		value = Scalar( rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255) );
		copyMakeBorder( img1, img2, top, bottom, left, right, border_type, value );
		imshow("Border image", img2 );
	}
	return 0;
}
