#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;

Mat img, img_gray;
Mat fn, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;

static void CannyThreshold(int, void*);

int main( int, char** argv )
{
  img = imread( argv[1], 1 ); 
  if(img.empty() )
  { 
  	return -1; 
	}
  fn.create( img.size(), img.type() );
  cvtColor( img, img_gray, COLOR_BGR2GRAY );
  namedWindow( "Canny", WINDOW_AUTOSIZE );
  createTrackbar( "Min Threshold:","Canny", &lowThreshold, max_lowThreshold, CannyThreshold );
  CannyThreshold(0, 0);
  waitKey(0);
  return 0;
}

static void CannyThreshold(int, void*)
{
    blur( img_gray, detected_edges, Size(3,3) );
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    fn = Scalar::all(0);
    img.copyTo( fn, detected_edges);
    imshow( "Canny", fn );
    
}
