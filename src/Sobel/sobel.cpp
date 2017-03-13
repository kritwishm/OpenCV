#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

int main( int, char** argv )
{
  Mat img, img_gray;
  Mat fn;
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;

  img = imread( argv[1], 1 );

  if( img.empty() )
    { return -1; }
  GaussianBlur( img, img, Size(3,3), 0, 0, BORDER_DEFAULT );
 
  cvtColor( img, img_gray, COLOR_BGR2GRAY );

  Mat grad_x, grad_y;
  Mat abs_grad_x, abs_grad_y;


  Sobel( img_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );


  Sobel( img_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );

  convertScaleAbs( grad_x, abs_grad_x );
  convertScaleAbs( grad_y, abs_grad_y );

  addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, fn );
	namedWindow("Sobel", CV_WINDOW_AUTOSIZE);
  imshow("Sobel", fn );
  waitKey(0);
  
  return 0;
}
