#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class Mier
{
public:
	Mier(Mat &src1, Mat &src2, Mat &dst);
	void process(void);

private:
	Mat src1, src2, dst;
};
