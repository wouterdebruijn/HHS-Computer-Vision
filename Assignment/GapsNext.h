#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class GapsNext
{
public:
	GapsNext(Mat &src, Mat &dst);
	void process(void);
	uint8_t labelPixel(uint16_t h, uint16_t w);
	int label;

private:
	Mat src, dst;
	int HEIGHT, WIDTH;
	int internalEdges[4][2][2] = {
		{{0, 255},
		 {255, 255}},
		{{255, 0},
		 {255, 255}},
		{{255, 255},
		 {255, 0}},
		{{255, 255},
		 {0, 255}}};

	int externalEdges[4][2][2] = {
		{{255, 0},
		 {0, 0}},
		{{0, 255},
		 {0, 0}},
		{{0, 0},
		 {0, 255}},
		{{0, 0},
		 {255, 0}}};
};
