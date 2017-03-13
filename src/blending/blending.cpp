#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
	Mat img1,img2,fn;
	double alpha,beta,input;
	img1=imread(argv[1], 1);
	img2=imread(argv[2], 1);
	cout<<"Enter the value of alpha:";	
	cin>>input;
	if(input>=0.0&&input<=1.0)
	{
		alpha=input;
	}
	if(!img1.data)
	{
		cout<<"Could not open  image 1"<<std::endl;
		return -1;
	}
	if(!img2.data)
	{	
		cout<<"Could not open  image 2"<<std::endl;
		return -1;
	}
	namedWindow("Display Window 1", CV_WINDOW_AUTOSIZE);
	imshow("Display Window 1", img1);
	namedWindow("Display Window 2", CV_WINDOW_AUTOSIZE);
	imshow("Display Window 2", img2);
	waitKey(0);
	namedWindow("Add Image",CV_WINDOW_AUTOSIZE);
	beta=(1.0-alpha);
	addWeighted(img1,alpha,img2,beta,0.0,fn);
	imshow("Add Image",fn);
	imwrite("addim.jpg",fn);	
	waitKey(0);
	return 0;
}

