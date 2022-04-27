#include "SmartContrast.h"
using namespace cv;
using namespace std;

#include <iostream>
#include "Parameters.h"

SmartContrast::SmartContrast(Mat &src, Mat &dst)
{
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void SmartContrast::process(void)
{
    int minValue = 255;
    int avgValueSum = 0;

    int h, w, temp = 0;
    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp = src.at<uchar>(h, w);
            if (temp < minValue)
            {
                minValue = temp;
            }
            avgValueSum = avgValueSum + temp;
        }
    }

    int avgValue = avgValueSum / (HEIGHT * WIDTH);

    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp = src.at<uchar>(h, w);
            dst.at<uchar>(h, w) = (temp - minValue) + (LEVELS / 2 - avgValue); // This needs to be changed to proper contrast stretching
        }
    }
}