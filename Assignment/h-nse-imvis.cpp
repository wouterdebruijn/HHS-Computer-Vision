#define ASSET_DIR "../assets/"

#include "opencv2/highgui.hpp"
#include <iostream>

#include "Parameters.h"
#include "Histogram.h"
#include "Mirror.h"
#include "Invert.h"
#include "SmartContrast.h"
#include "Zoom.h"
#include "Filtering.h"
#include "Mier.h"
#include "Gaps.h"
#include "GapsNext.h"

using namespace cv;
using namespace std;

int lab1_opdracht1a_beeld_spiegelen()
{
    // 1. Spiegelen
    Mat src, dst;

    String source_window = "Originele plaatje"; // Mag je weglaten, alleen imshow("naam",src) is voldoende. Dit maakt het mooier.
    String destination_window = "Verticaal gespiegeld";

    /* Hieronder: plaatje inlezen met imread(). De paden moet er zo uitzien: "C://mijnMap//subMap//bestand.pgm"
    Vergeet de optie IMREAD_GRAYSCALE niet als je een grijswaardenplaatje inleest.
    Met IMREAD_GRAYSCALE krijg je 1 byte per pixel, als je het vergeet krijg je 3 bytes per pixel en dan zie je maar 1/3 van je bronplaatje terug!! */

    src = imread(ASSET_DIR "image1.pgm", IMREAD_GRAYSCALE);
    namedWindow(source_window, WINDOW_AUTOSIZE); // Mag je weglaten, alleen imshow("naam",src) is voldoende.
    imshow(source_window, src);                  // Originele plaatje laten zien.
    int HEIGHT = src.rows;
    int WIDTH = src.cols;
    int temp = 0;

    dst = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0; // Maak een nieuw plaatje van hetzelfde type als src, gevuld met 1 * 0 (dus nullen, dus zwart)

    Mirror spiegel(src, dst);
    spiegel.process();

    namedWindow(destination_window, WINDOW_AUTOSIZE); // Mag je weglaten, alleen imshow("naam",src) is voldoende.
    imshow(destination_window, dst);                  // Bestemmingsplaatje laten zien.

    // Plaatjes netjes positioneren (mag je weglaten, alleen imshow() is voldoende)
    moveWindow(source_window, 0, 0);          // Plaatje naar linksboven verplaatsen
    moveWindow(destination_window, WIDTH, 0); // Plaatje rechts naast de andere plaatsen

    waitKey(0); // Wachten tot een toets gedrukt wordt...
    return 0;
}

int lab1_opdracht1b_grijswaarden_inverteren()
{
    // 2. Zwart en wit tinten inverteren
    Mat src, dst;

    String source_window = "Originele plaatje";
    String destination_window = "Inverted";

    // Load original image
    src = imread(ASSET_DIR "image1.pgm", IMREAD_GRAYSCALE);

    // Show original image
    namedWindow(source_window, WINDOW_AUTOSIZE);
    imshow(source_window, src);

    int HEIGHT = src.rows;
    int WIDTH = src.cols;
    int temp = 0;

    // Create new image that is the same type as the original image, but without the data
    dst = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;

    // Change the image using the Invert class
    Invert invert(src, dst);
    invert.process();

    // Show the inverted image
    namedWindow(destination_window, WINDOW_AUTOSIZE);
    imshow(destination_window, dst);

    waitKey(0); // Wachten tot een toets gedrukt wordt...
    return 0;
}

int lab1_opdracht2_contrast_stretch()
{
    // 3. Contrast aanpassen
    Mat src, dst;

    String source_window = "Originele plaatje";
    String destination_window = "Contrast Stretched";

    // Load original image
    src = imread(ASSET_DIR "Donker.pgm", IMREAD_GRAYSCALE);

    // Show original image
    namedWindow(source_window, WINDOW_AUTOSIZE);
    imshow(source_window, src);

    int HEIGHT = src.rows;
    int WIDTH = src.cols;
    int temp = 0;

    // Create new image that is the same type as the original image, but without the data
    dst = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;

    // Change the image using the Invert class
    SmartContrast smartContrast(src, dst);
    smartContrast.process();

    // Show the inverted image
    namedWindow(destination_window, WINDOW_AUTOSIZE);
    imshow(destination_window, dst);

    // Show Histograms
    Histogram srcHistogram("Source", src);
    Histogram dstHistogram("Processed", dst);

    while (1)
    {
        char c = waitKey(5);
        if (c == 27)
        {
            // ESC key pressed
            break;
        }

        srcHistogram.update();
        dstHistogram.update();
    }

    return 0;
}

int lab2_opdracht2_zoomen()
{
    // 4. Zoomen
    // 2. Zwart en wit tinten inverteren
    Mat src, dst;

    String source_window = "Originele plaatje";
    String destination_window = "Zoom";

    // Load original image
    src = imread(ASSET_DIR "Rijswijk.pgm", IMREAD_GRAYSCALE);

    // Show original image
    namedWindow(source_window, WINDOW_AUTOSIZE);
    imshow(source_window, src);

    int HEIGHT = src.rows;
    int WIDTH = src.cols;
    int temp = 0;

    // Read zoomFactor from user input
    cout << "Enter zoom factor: ";
    float zoomFactor;
    cin >> zoomFactor;

    cout << "Enter x: ";
    int x;
    cin >> x;

    cout << "Enter y: ";
    int y;
    cin >> y;

    while (1)
    {
        char c = waitKey(5);
        if (c == 27)
        {
            // ESC key pressed
            break;
        }

        if (c == '+')
        {
            zoomFactor += 0.1;
        }
        else if (c == '-')
        {
            zoomFactor -= 0.1;
        }
        else if (c == 'a')
        {
            x -= 10;
        }
        else if (c == 'd')
        {
            x += 10;
        }
        else if (c == 'w')
        {
            y -= 10;
        }
        else if (c == 's')
        {
            y += 10;
        }

        dst = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;

        // Change the image using the Invert class
        Zoom zoom(src, dst, zoomFactor, x, y);
        zoom.process();

        // Show the inverted image
        namedWindow(destination_window, WINDOW_AUTOSIZE);
        imshow(destination_window, dst);
    }

    return 0;
}

int lab2_opdracht2b_roteren()
{
    // 5. Roteren
    return 0;
}

int lab2_opdracht3_affien_mysterie()
{
    // 6. Mysterieuze affiene transformatie
    return 0;
}

int lab3_opdracht1_hoogdoorlaat()
{
    // 7. Hoogdoorlaat filter
    Mat src, dst;

    String source_window = "Originele plaatje";
    String destination_window = "Filtered";

    // Load original image
    src = imread(ASSET_DIR "joint.jpg", IMREAD_GRAYSCALE);

    // Show original image
    namedWindow(source_window, WINDOW_AUTOSIZE);
    imshow(source_window, src);

    int HEIGHT = src.rows;
    int WIDTH = src.cols;
    int temp = 0;

    // Create new image that is the same type as the original image, but without the data
    dst = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;

    // Change the image using the Invert class
    Filtering filtering(src, dst);
    filtering.hdFilter();

    // Show the inverted image
    namedWindow(destination_window, WINDOW_AUTOSIZE);
    imshow(destination_window, dst);

    waitKey(0); // Wachten tot een toets gedrukt wordt...
    return 0;
}

int lab3_opdracht2a_laagdoorlaat()
{
    // 8. Laagdoorlaat filter
    Mat src, dst;

    String source_window = "Originele plaatje";
    String destination_window = "Filtered";

    // Load original image
    src = imread(ASSET_DIR "whalesp.jpg", IMREAD_GRAYSCALE);

    // Show original image
    namedWindow(source_window, WINDOW_AUTOSIZE);
    imshow(source_window, src);

    int HEIGHT = src.rows;
    int WIDTH = src.cols;
    int temp = 0;

    // Create new image that is the same type as the original image, but without the data
    dst = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;

    // Change the image using the Invert class
    Filtering filtering(src, dst);
    filtering.ldFilter();

    // Show the inverted image
    namedWindow(destination_window, WINDOW_AUTOSIZE);
    imshow(destination_window, dst);

    waitKey(0); // Wachten tot een toets gedrukt wordt...
    return 0;
}

int lab3_opdracht2b_mediaan()
{
    // 9. Mediaan filter
    Mat src, dst;

    String source_window = "Originele plaatje";
    String destination_window = "Filtered";

    // Load original image
    src = imread(ASSET_DIR "whalesp.jpg", IMREAD_GRAYSCALE);

    // Show original image
    namedWindow(source_window, WINDOW_AUTOSIZE);
    imshow(source_window, src);

    int HEIGHT = src.rows;
    int WIDTH = src.cols;
    int temp = 0;

    // Create new image that is the same type as the original image, but without the data
    dst = Mat::ones(HEIGHT, WIDTH, CV_8U) * 0;

    // Change the image using the Invert class
    Filtering filtering(src, dst);
    filtering.medianFilter();

    // Show the inverted image
    namedWindow(destination_window, WINDOW_AUTOSIZE);
    imshow(destination_window, dst);

    waitKey(0); // Wachten tot een toets gedrukt wordt...
    return 0;
}

int lab4_opdracht3_mieren()
{
    // 10. Mier(en)
    Mat src, src2;
    src = imread(ASSET_DIR "ants1_bw.pgm", IMREAD_GRAYSCALE);
    src2 = imread(ASSET_DIR "ants2_bw.pgm", IMREAD_GRAYSCALE);

    Mat dst = Mat::ones(src.rows, src.cols, CV_8U) * 0;
    Mier mier(src, src2, dst);

    mier.process();

    namedWindow("Result", WINDOW_AUTOSIZE);
    imshow("Result", dst);

    waitKey(0);

    return 0;
}

int lab5_opdracht1_gaten_tellen()
{
    // 11. Gaten tellen1
    Mat src, src2;
    src = imread(ASSET_DIR "chassis1.pgm", IMREAD_GRAYSCALE);

    namedWindow("Source", WINDOW_AUTOSIZE);
    imshow("Source", src);

    Mat dst = Mat::ones(src.rows, src.cols, CV_8U) * 0;
    Gaps gaps(src, dst);

    gaps.process();
    waitKey(0);

    return 0;
}

int lab5_opdracht2_labellen()
{
    // 12. Gaten tellen2 - verbeterd
    Mat src;
    src = imread(ASSET_DIR "chassis2.pgm", IMREAD_GRAYSCALE);

    Mat dst = Mat::ones(src.rows, src.cols, CV_8U) * 0;

    GapsNext gapsNext(src, dst);
    gapsNext.process();

    namedWindow("Source", WINDOW_AUTOSIZE);
    imshow("Source", src);

    waitKey(0);

    return 0;
}

int main(int argc, const char **argv)
{
    int optie, ret;

    do
    {
        cout << "\033[1;32m";
        cout << "H-NSE-IMVIS   -   Maak een keuze (geef nummer + druk Enter)" << endl;
        cout << "\033[0;32m";
        cout << "-1: Demo met camera en histogram" << endl;
        cout << " 1: Lab 1 Opdracht 1a - Spiegelen" << endl;
        cout << " 2: Lab 1 Opdracht 1b - Inverteren" << endl;
        cout << " 3: Lab 1 Opdracht 2  - Contrast aanpassen" << endl;
        cout << " 4: Lab 2 Opdracht 2  - Affien: Zoomen" << endl;
        cout << " 5: Lab 2 Opdracht 2b - Affien: Roteren" << endl;
        cout << " 6: Lab 2 Opdracht 3  - Mysterieuze affiene transformatie - LET OP! : TOETSVRAGEN!" << endl;
        cout << " 7: Lab 3 Opdracht 1  - Hoogdoorlaat filter" << endl;
        cout << " 8: Lab 3 Opdracht 2a - Laagdoorlaat filter" << endl;
        cout << " 9: Lab 3 Opdracht 2b - Mediaan filter" << endl;
        cout << "10: Lab 4 Opdracht 3  - Mier(en)" << endl;
        cout << "11: Lab 5 Opdracht 1  - Gaten tellen1" << endl;
        cout << "12: Lab 5 Opdracht 2  - Gaten tellen2 - verbeterd" << endl;
        cout << endl
             << "Maak een keuze (0 = stoppen): ";
        cin >> optie;

        switch (optie)
        {
        case 0:
            ret = 0;
            break;
        case 1:
            ret = lab1_opdracht1a_beeld_spiegelen();
            break;
        case 2:
            ret = lab1_opdracht1b_grijswaarden_inverteren();
            break;
        case 3:
            ret = lab1_opdracht2_contrast_stretch();
            break;
        case 4:
            ret = lab2_opdracht2_zoomen();
            break;
        case 5:
            ret = lab2_opdracht2b_roteren();
            break;
        case 6:
            ret = lab2_opdracht3_affien_mysterie();
            break;
        case 7:
            ret = lab3_opdracht1_hoogdoorlaat();
            break;
        case 8:
            ret = lab3_opdracht2a_laagdoorlaat();
            break;
        case 9:
            ret = lab3_opdracht2b_mediaan();
            break;
        case 10:
            ret = lab4_opdracht3_mieren();
            break;
        case 11:
            ret = lab5_opdracht1_gaten_tellen();
            break;
        case 12:
            ret = lab5_opdracht2_labellen();
            break;
        }

        if (ret != 0)
            return ret;
        destroyAllWindows(); // Alle openstaande imshow() vensters sluiten
    } while (optie != 0);
    return 0;
}
