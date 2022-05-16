#include "Zoom.h"

#include <iostream>

using namespace cv;
using namespace std;

Zoom::Zoom(Mat &src, Mat &dst)
{
    this->src = src;
    this->dst = dst;
    HEIGHT = src.rows;
    WIDTH = src.cols;
}

void Zoom::process(void)
{
    int targetX = WIDTH / 4;
    int targetY = HEIGHT / 4;

    float move_matrix[3][3] = {
        {1, 0, -targetY},
        {0, 1, -targetX},
        {0, 0, 1}};

    float zoom_matrix[3][3] = {
        {2, 0, 0},
        {0, 2, 0},
        {0, 0, 2}};

    float move_back_matrix[3][3] = {
        {1, 0, targetY},
        {0, 1, targetX},
        {0, 0, 1}};

    Mat test1 = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;
    Mat test2 = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // Calculate the new coordinates
            int new_x = (move_matrix[0][0] * i) + (move_matrix[0][1] * j) + (move_matrix[0][2] * 1);
            int new_y = (move_matrix[1][0] * i) + (move_matrix[1][1] * j) + (move_matrix[1][2] * 1);

            // Check if the new coordinates are within the image
            if (new_x >= 0 && new_x < HEIGHT && new_y >= 0 && new_y < WIDTH)
            {
                // Copy the pixel from the original image to the destination image
                test1.at<uchar>(new_x, new_y) = src.at<uchar>(i, j);
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // Calculate the new coordinates
            int new_x = (zoom_matrix[0][0] * i) + (zoom_matrix[0][1] * j) + (zoom_matrix[0][2] * 1);
            int new_y = (zoom_matrix[1][0] * i) + (zoom_matrix[1][1] * j) + (zoom_matrix[1][2] * 1);

            // Check if the new coordinates are within the image
            if (new_x >= 0 && new_x < HEIGHT && new_y >= 0 && new_y < WIDTH)
            {
                // Copy the pixel from the original image to the destination image
                dst.at<uchar>(new_x, new_y) = test1.at<uchar>(i, j);
            }
        }
    }

    // for (int i = 0; i < HEIGHT; i++)
    // {
    //     for (int j = 0; j < WIDTH; j++)
    //     {
    //         // Calculate the new coordinates
    //         int new_x = (move_back_matrix[0][0] * i) + (move_back_matrix[0][1] * j) + (move_back_matrix[0][2] * 1);
    //         int new_y = (move_back_matrix[1][0] * i) + (move_back_matrix[1][1] * j) + (move_back_matrix[1][2] * 1);

    //         // Check if the new coordinates are within the image
    //         if (new_x >= 0 && new_x < HEIGHT && new_y >= 0 && new_y < WIDTH)
    //         {
    //             // Copy the pixel from the original image to the destination image
    //             dst.at<uchar>(new_x, new_y) = test2.at<uchar>(i, j);
    //         }
    //     }
    // }
}