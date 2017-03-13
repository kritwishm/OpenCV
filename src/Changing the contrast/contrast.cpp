#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
	Mat img;
	img=imread(argv[1], 1);
	Mat new_img=Mat::zeros(img.size(),img.type());
	double alpha;
	int beta;
	if(!img.data)
	{
		cout<<"Could not open  image"<<std::endl;
		return -1;
	}
	namedWindow("Display Window", CV_WINDOW_AUTOSIZE);
	imshow("Display Window", img);
	waitKey(0);
	cout<<"Enter the value of alpha[1.0-3.0]:";
	cin>>alpha;
	cout<<"Enter the value of beta[1-100]:";
	cin>>beta;
	for(int x=0;x<img.rows;x++){
		for(int y=0;y<img.cols;y++){
			for(int c=0;c<3;c++){
				new_img.at<Vec3b>(x,y)[c] =
				saturate_cast<uchar>( alpha*( img.at<Vec3b>(x,y)[c] )+beta);
			}		
		}	
	}
	namedWindow("changed contrast", CV_WINDOW_AUTOSIZE);
	imshow("changed contrast",new_img);
	waitKey();
	return 0;
}

