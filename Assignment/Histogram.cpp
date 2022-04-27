#include "Histogram.h"
using namespace cv;
using namespace std;

Histogram::Histogram(const String& winname, Mat& src) {
	this->winname = winname;
	this->src = src;
	namedWindow(winname, WINDOW_AUTOSIZE);
	createTrackbar("greyvalue", winname, &_pixelvalue, 255);
	histImage = Scalar::all(255);
}

void Histogram::update() {
	if (src.channels() == 3) // RGB plaatje, dus converteren
		cvtColor(src, dst, COLOR_RGB2GRAY); // Converteer (kleuren) bronplaatje naar 8 bits per pixel grijswaarden plaatje.
	else
		src.copyTo(dst);
	calcHist(&dst, 1, 0, Mat(), histI, 1, &histSize, 0);
	histImage = Mat::ones(200, 256, CV_8U) * 255;
	normalize(histI, histO, 0, histImage.rows, NORM_MINMAX, CV_32F);
	histImage = Scalar::all(255);
	int binW = cvRound((double)histImage.cols / histSize);
	for (int i = 0; i < histSize; i++)
		rectangle(histImage, Point(i * binW, histImage.rows),
			Point((i + 1) * binW, histImage.rows - cvRound(histO.at<float>(i))),
			Scalar::all(0), -1, 8, 0);
	line(histImage, Point(_pixelvalue, histImage.rows), Point(_pixelvalue, 0), Scalar::all(127)); // grijze verticale lijn
	putText(histImage, "#pixels:", Point(10, 15), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar::all(127), 1, 8);
	putText(histImage, to_string(cvRound(histI.at<float>(_pixelvalue))), Point(10, 40), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar::all(127), 1, 8);
	imshow(this->winname, histImage);
}