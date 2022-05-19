#include "Filtering.h"

#include <iostream>

using namespace cv;
using namespace std;

Filtering::Filtering(Mat &src, Mat &dst)
{
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Filtering::hdFilter(void)
{
    // Define kernel
    int kernel[3][3] = {
        {-1, -1, -1},
        {-1, 9, -1},
        {-1, -1, -1}};

    // Loop through the image
    for (int h = 0; h < HEIGHT; h++)
    {
        for (int w = 0; w < WIDTH; w++)
        {
            int sum = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int y, x;
                    y = h + i - 1;
                    x = w + j - 1;

                    if (y < 0)
                        y = 0;

                    if (y >= HEIGHT)
                        y = HEIGHT - 1;

                    if (x < 0)
                        x = 0;

                    if (x >= WIDTH)
                        x = WIDTH - 1;

                    sum += kernel[i][j] * (int16_t)src.at<uchar>(y, x);
                }
            }

            if (sum < 0)
                sum = 0;
            if (sum > 255)
                sum = 255;

            dst.at<uchar>(h, w) = (uint8_t)sum;
        }
    }
}

void Filtering::ldFilter(void)
{
    // Define kernel
    int kernel[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};

    // Loop through the image
    for (int h = 0; h < HEIGHT; h++)
    {
        for (int w = 0; w < WIDTH; w++)
        {
            int sum = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int y, x;
                    y = h + i - 1;
                    x = w + j - 1;

                    if (y < 0)
                        y = 0;

                    if (y >= HEIGHT)
                        y = HEIGHT - 1;

                    if (x < 0)
                        x = 0;

                    if (x >= WIDTH)
                        x = WIDTH - 1;

                    sum += kernel[i][j] * (int16_t)src.at<uchar>(y, x);
                }
            }

            // Normalize the sum
            sum /= 9;

            if (sum < 0)
                sum = 0;
            if (sum > 255)
                sum = 255;

            dst.at<uchar>(h, w) = (uint8_t)sum;
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void Filtering::medianFilter(void)
{
    int window[9] = {0};

    for (int h = 0; h < HEIGHT; h++)
    {
        for (int w = 0; w < WIDTH; w++)
        {
            window[0] = src.at<uchar>(h - 1, w - 1);
            window[1] = src.at<uchar>(h - 1, w);
            window[2] = src.at<uchar>(h - 1, w + 1);
            window[3] = src.at<uchar>(h, w - 1);
            window[4] = src.at<uchar>(h, w);
            window[5] = src.at<uchar>(h, w + 1);
            window[6] = src.at<uchar>(h + 1, w - 1);
            window[7] = src.at<uchar>(h + 1, w);
            window[8] = src.at<uchar>(h + 1, w + 1);

            // sort window array
            insertionSort(window, 9);
            dst.at<uchar>(h, w) = window[4];
        }
    }
}