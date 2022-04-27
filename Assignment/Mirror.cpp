#include "Mirror.h"
using namespace cv;
using namespace std;

Mirror::Mirror(Mat& src, Mat& dst) {
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Mirror::process(void){
	int h, w, temp = 0;
    for (h = 0; h < HEIGHT; h++) {
        for (w = 0; w < WIDTH; w++) {

            temp = src.at<uchar>(h, w);
            //temp = *src.ptr(h, w); // hetzelfde als hierboven, maar op een andere manier.

            dst.at<uchar>(HEIGHT - h - 1, w) = temp;
            //*dst.ptr(HEIGHT - h - 1, w) = temp; // hetzelfde als hierboven, maar op een andere manier.
        }
    }
}