#include <iostream>
#include <stdlib.h>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
char* trackbar_value = "Value";
void Threshold_Demo(int , void* );

char* window_name = "threshold";

Mat img1,img2,fn;

int main(int argc, char** argv){
	img1=imread(argv[1], 1);
	cvtColor(img1,img2,CV_RGB2GRAY);
	if(!img1.data)
	{
		cout<<"Could not open  image"<<std::endl;
		return -1;
	}
	namedWindow("Display Window", CV_WINDOW_AUTOSIZE);
	imshow("Display Window", img1);
	waitKey(0);
	namedWindow( window_name, CV_WINDOW_AUTOSIZE );
	createTrackbar(trackbar_type,window_name, &threshold_type,max_type,Threshold_Demo );
	createTrackbar( trackbar_value,window_name, &threshold_value,max_value, Threshold_Demo);	
	Threshold_Demo(0,0);	
	/*while(true)
	{
		int c;
		c = waitKey( 20 );
		if( (char)c == 27 )
		{ break; }
	}*/
	waitKey(0);
	return 0;
}

void Threshold_Demo( int, void * )
{
	threshold( img2, fn, threshold_value, max_BINARY_value, threshold_type );
	imshow( window_name, fn );
}
