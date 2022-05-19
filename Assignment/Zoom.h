#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class Zoom
{
public:
	Zoom(Mat &src, Mat &dst, float zoomFactor, int x, int y);
	void process(void);

private:
	Mat src, dst;
	int HEIGHT, WIDTH;
	float zoomFactor;
	int x,y;
};
