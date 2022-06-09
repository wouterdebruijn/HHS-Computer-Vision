#include "Gaps.h"
using namespace cv;
using namespace std;

#include <iostream>
#include "Parameters.h"

Gaps::Gaps(Mat &src, Mat &dst)
{
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Gaps::process(void)
{
    int h, w;

    uint32_t internalEdgeCount = 0;
    uint32_t externalEdgeCount = 0;

    for (h = 0; h < HEIGHT; h++)
    {
        for (w = 0; w < WIDTH; w++)
        {
            // Check for matching edges
            for (int i = 0; i < 4; i++)
            {
                if ((h + 1) <= HEIGHT && (w + 1) <= WIDTH)
                    if (src.at<uchar>(h, w) == internalEdges[i][0][0] &&
                        src.at<uchar>(h, w + 1) == internalEdges[i][0][1] &&
                        src.at<uchar>(h + 1, w) == internalEdges[i][1][0] &&
                        src.at<uchar>(h + 1, w + 1) == internalEdges[i][1][1])
                    {
                        internalEdgeCount++;
                    }

                if ((h + 1) <= HEIGHT && (w + 1) <= WIDTH)
                    if (src.at<uchar>(h, w) == externalEdges[i][0][0] &&
                        src.at<uchar>(h, w + 1) == externalEdges[i][0][1] &&
                        src.at<uchar>(h + 1, w) == externalEdges[i][1][0] &&
                        src.at<uchar>(h + 1, w + 1) == externalEdges[i][1][1])
                    {
                        externalEdgeCount++;
                    }
            }
        }
    }
    cout << "Internal edge count: " << internalEdgeCount << endl;
    cout << "External edge count: " << externalEdgeCount << endl;
    double gapCount = (externalEdgeCount - internalEdgeCount) / 4;

    cout << "Gap count: " << gapCount << endl;
}