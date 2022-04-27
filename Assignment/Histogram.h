#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

class Histogram {
public:
	Histogram(const String& winname, Mat& src);
	void update();
private:
	int _pixelvalue = 127; // beginwaarde voor trackbar waarde
	int histSize = 256; // Totaal aantal grijswaarden
	String winname;
	Mat src, dst, histI, histO, histImage;
};

