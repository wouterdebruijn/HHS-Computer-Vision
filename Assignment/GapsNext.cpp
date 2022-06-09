#include "GapsNext.h"
using namespace cv;
using namespace std;

#include <iostream>
#include "Parameters.h"

GapsNext::GapsNext(Mat &src, Mat &dst)
{
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

uint8_t GapsNext::labelPixel(uint16_t h, uint16_t w)
{
    int16_t i, j;

    if ((src.at<uchar>(h, w) == 255) && (dst.at<uchar>(h, w) == 0))
    {
        dst.at<uchar>(h, w) = label;
        for (i = -1; i < 2; i++)
        {
            for (j = -1; j < 2; j++)
            {
                if (((i != 0) || (j != 0)) && (h + i >= 0) &&
                    (h + i < HEIGHT) && (w + j >= 0) && (w + j < WIDTH))
                {
                    labelPixel(h + i, w + j);
                }
            }
        }
        return 255;
    }
    return 0;
}

void GapsNext::process(void)
{
    int16_t h, w;

    for (h = 0; h < HEIGHT; h++)
        for (w = 0; w < WIDTH; w++)
        {
            dst.at<uchar>(h, w) = 0;
        }

    label = 0;

    for (h = 1; h < HEIGHT -1; h++)
    {
        for (w = 1; w < WIDTH - 1; w++)
        {
            if ((labelPixel(h, w) != 0) && (label < 254))
            {
                label++;
                cout << "Label: " << label << endl;
            }
        }
    }
}