//
//  allocationDefects.cpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 24.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "allocationDefects.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
using namespace cv;

allocationDefects::~allocationDefects() { 
    imgMatrix.deallocate();
}

allocationDefects::allocationDefects(cv::Mat matrix) { 
    imgMatrix = matrix;
}

cv::Mat &allocationDefects::exportResultMatrix() { 
    return resultMatrix;
}

void allocationDefects::exportResultToDisk(std::string filePath) { 
    imwrite(filePath + "result4.jpg", resultMatrix);
}

void allocationDefects::showResult() { 
    std::string name = "выделение дефектов";
    namedWindow(name);
    imshow(name, resultMatrix);
    waitKey();
    destroyWindow(name);
}

void allocationDefects::labelWholeTeeth(int diametr) { 
    Mat teethCirkul(diametr, diametr, CV_8UC1);
    circle(teethCirkul, {diametr/2, diametr/2}, diametr/2, 255);
    dilate(imgMatrix, resultMatrix, teethCirkul);
}

