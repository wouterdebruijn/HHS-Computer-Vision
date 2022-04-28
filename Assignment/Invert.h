#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class Invert
{
public:
	Invert(Mat &src, Mat &dst);
	void process(void);

private:
	Mat src, dst;
	int HEIGHT, WIDTH;
};
