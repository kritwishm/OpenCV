#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
	Mat img,cropped;
	img=imread(argv[1], 0);
	if(!img.data)
	{
		cout<<"Could not open  image"<<std::endl;
		return -1;
	}
	namedWindow("Display Window", CV_WINDOW_AUTOSIZE);
	imshow("Display Window", img);
	cout<<"Width: "<<img.size().width<<endl;
	cout<<"Height: "<<img.size().height<<endl;
	waitKey(0);
	Rect croppedrectangle = Rect(98,11,157,189);
	cropped=img(croppedrectangle);
	namedWindow("cropped Window", CV_WINDOW_AUTOSIZE);
	imshow("cropped Window",cropped);
	waitKey(0);
	return 0;
}

