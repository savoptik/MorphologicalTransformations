///
//  CreatorКing.cpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 20.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "CreatorRing.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

CreatorRing::CreatorRing(cv::Mat &matrix) {
    image = matrix;
}

void CreatorRing::disconnection(int diameter) {
    Mat disk(diameter, diameter, CV_8UC1);
    circle(disk, {diameter/2, diameter/2}, diameter/2, 255);
//    imshow("диск", disk); waitKey();
    Mat tMat(image.rows, image.cols, CV_8UC1);
    erode(image, tMat, disk);
//    imshow("результат эрозии", tMat); waitKey();
    auto eliment = getStructuringElement(2, Size(diameter+7, diameter+7));
    dilate(tMat, tMat, eliment);
//    imshow("результат расширения", tMat); waitKey();
    result = image - tMat;
}

CreatorRing::~CreatorRing() {
    image.deallocate();
}

void CreatorRing::showResult() { 
    std::string name = "Результат размыкания";
    namedWindow(name);
    imshow(name, result);
    waitKey();
    destroyWindow(name);
}

