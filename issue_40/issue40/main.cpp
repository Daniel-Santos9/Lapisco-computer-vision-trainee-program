#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(){

    Mat img_gray, thr;
    Mat src = imread("../img2.png");
    if(!src.data){
        cout<<"Image not found"<<endl;
        exit(0);
    }

    cvtColor(src,img_gray, CV_RGB2GRAY);

    namedWindow("Gray Image",CV_WINDOW_NORMAL);
    imshow("Gray Image",img_gray);
    waitKey(0);
    destroyWindow("Gray Image");

    threshold(img_gray, thr, 127, 255, CV_THRESH_OTSU);


    namedWindow("Image Otsu",CV_WINDOW_NORMAL);
    imshow("Image Otsu",img_gray);
    waitKey(0);
    destroyWindow("Image Otsu");

    Mat element = getStructuringElement(CV_SHAPE_RECT, Size(3,1));
    for(int i=0; i<70; i++){
        erode(thr, thr, element);
        imshow("Erode", thr);
        waitKey(20);
    }

    return 0;
}
