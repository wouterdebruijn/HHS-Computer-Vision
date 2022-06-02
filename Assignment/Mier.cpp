#include "Mier.h"

#include <iostream>

using namespace cv;
using namespace std;

Mier::Mier(Mat &src1, Mat &src2, Mat &dst)
{
    this->src1 = src1;
    this->src2 = src2;
    this->dst = dst;
}

void xorOperation(Mat &src1, Mat&src2, Mat &dst)
{
    for (int i = 0; i < src1.rows; i++)
    {
        for (int j = 0; j < src1.cols; j++)
        {
            dst.at<uchar>(i, j) = src1.at<uchar>(i, j) ^ src2.at<uchar>(i, j);
        }
    }
}

void erosion(Mat &src, Mat &dst) {
    for (int y = 0; y < src.rows; y++)
    {
        for (int x = 0; x < src.cols; x++)
        {
            if (x <= 1 || y <= 1 || x >= src.cols - 1 || y >= src.rows - 1)
                continue;
            
            // Pixel Erosion
            int pix = src.at<uchar>(y, x);
            int pix_top = src.at<uchar>(y - 1, x);
            int pix_bottom = src.at<uchar>(y + 1, x);
            int pix_left = src.at<uchar>(y, x - 1);
            int pix_right = src.at<uchar>(y, x + 1);
            int pix_top_left = src.at<uchar>(y - 1, x - 1);
            int pix_top_right = src.at<uchar>(y - 1, x + 1);
            int pix_bottom_left = src.at<uchar>(y + 1, x - 1);
            int pix_bottom_right = src.at<uchar>(y + 1, x + 1);

            if (pix == 0 || pix_top == 0 || pix_bottom == 0 || pix_left == 0 || pix_right == 0 || pix_top_left == 0 || pix_top_right == 0 || pix_bottom_left == 0 || pix_bottom_right == 0)
            {
                dst.at<uchar>(y, x) = 0;
            }
            else
            {
                dst.at<uchar>(y, x) = 255;
            }
        }
    }
}

void dilation(Mat &src, Mat &dst) {
    // For every pixel in the image
    for (int y = 0; y < src.rows; y++)
    {
        for (int x = 0; x < src.cols; x++)
        {
            if (x <= 1 || y <= 1 || x >= src.cols - 1 || y >= src.rows - 1)
                continue;
            
            int pix = src.at<uchar>(y, x);
            int pix_top = src.at<uchar>(y - 1, x);
            int pix_bottom = src.at<uchar>(y + 1, x);
            int pix_left = src.at<uchar>(y, x - 1);
            int pix_right = src.at<uchar>(y, x + 1);
            int pix_top_left = src.at<uchar>(y - 1, x - 1);
            int pix_top_right = src.at<uchar>(y - 1, x + 1);
            int pix_bottom_left = src.at<uchar>(y + 1, x - 1);
            int pix_bottom_right = src.at<uchar>(y + 1, x + 1);

            if (pix != 0 || pix_top != 0 || pix_bottom != 0 || pix_left != 0 || pix_right != 0 || pix_top_left != 0 || pix_top_right != 0 || pix_bottom_left != 0 || pix_bottom_right != 0)
            {
                dst.at<uchar>(y, x) = 255;
            }
            else
            {
                dst.at<uchar>(y, x) = 0;
            }
        }
    }
}

void Mier::process(void)
{
    Mat tmp1 = Mat::ones(src1.rows, src1.cols, CV_8U) * 0;
    Mat tmp2 = Mat::ones(src1.rows, src1.cols, CV_8U) * 0;
    Mat tmp3 = Mat::ones(src1.rows, src1.cols, CV_8U) * 0;
    xorOperation(src1, src2, tmp1);
    erosion(tmp1, tmp2);
    erosion(tmp2, tmp3);
    dilation(tmp3, dst);
}