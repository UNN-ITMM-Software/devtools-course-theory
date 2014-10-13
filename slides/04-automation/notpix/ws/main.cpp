#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if (argc <= 1)
        return 1;

    Mat image = imread(argv[1]);
    Mat map1, map2;
    Mat K = Mat_<float>(3, 3) <<
            1111.159649, 0.000000, 636.153830,
            0.000000, 1108.873348, 408.734602,
            0.000000, 0.000000, 1.000000;

    Mat D = Mat_<float>(1, 5) <<
            -0.357957, 0.157295, 0.000437, -0.000640, 0.000000;

    Mat R = Mat_<float>(3, 3) <<
            0.999423, 0.021785, -0.026058,
            -0.022180, 0.999642, -0.014960,
            0.025723, 0.015529, 0.999548;

    Mat P = Mat_<float>(3, 3) <<
			1115.036722, 0.000000, 594.964981,         
			0.000000, 1115.036722, 408.455673,     
            0.000000, 0.000000, 1.000000;

    initUndistortRectifyMap(K, D, R, P, image.size(), CV_32FC1, map1, map2);

    Mat rectified;
    remap(image, rectified, map1, map2, INTER_LINEAR, BORDER_CONSTANT);

    cv::imshow("rectified", rectified);
    waitKey(0);
}
