#include "Invert.h"
using namespace cv;
using namespace std;

#include <iostream>
#include "Parameters.h"

Invert::Invert(Mat &src, Mat &dst)
{
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Invert::process(void)
{
    int h, w, temp = 0;
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {

            temp = src.at<uchar>(h, w);

            // Invert the pixel value by subtracting it from the maximum value.
            dst.at<uchar>(h, w) = LEVELS - temp;
        }
    }
}