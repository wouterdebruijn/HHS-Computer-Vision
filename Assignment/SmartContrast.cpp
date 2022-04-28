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
    int maxValue = 0;

    int h, w, temp = 0;

    int histogram[256] = {0};

    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp = src.at<uchar>(h, w);
            histogram[temp]++;
        }
    }

    for (int i = 256; i > 0; i--)
    {
        if (histogram[i] > 200)
        {
            maxValue = i;
            break;
        }
    }

    for (int i = 0; i < 256; i++)
    {
        if (histogram[i] > 200)
        {
            minValue = i;
            break;
        }
    }

    cout << "minValue: " << minValue << endl;
    cout << "maxValue: " << maxValue << endl;

    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            temp = src.at<uchar>(h, w);
            int newValue = (float)(temp - minValue) / (maxValue - minValue) * 255;

            // Prevent "clipping"
            if (newValue > 255)
                newValue = 255;

            if (newValue < 0)
                newValue = 0;

            dst.at<uchar>(h, w) = newValue;
        }
    }
}