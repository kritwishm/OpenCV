#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int max_kernel=31;

int main(int argc, char** argv){
	Mat img,fn;
	img=imread(argv[1], 1);
	fn=img.clone();
	if(!img.data)
	{
		cout<<"Could not open  image"<<std::endl;
		return -1;
	}
	namedWindow("Display Window", CV_WINDOW_AUTOSIZE);
	imshow("Display Window", img);
	waitKey(0);
	for(int i=1;i<max_kernel;i+=2){
		GaussianBlur(img,fn,Size(i,i),0,0);	
	}
	namedWindow("blur Window", CV_WINDOW_AUTOSIZE);
	imshow("blur Window",fn);
	imwrite("blurlena.jpg",fn);
	waitKey(0);
	return 0;
}

