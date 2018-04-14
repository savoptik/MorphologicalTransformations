//
//  holeRing.cpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 10.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "holeRing.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
using namespace cv;

cv::Mat &holeRing::extracktIMG() { 
    return resultImage; //возврат результирующего изображения.
}

void holeRing::closingHolis(int radius) { 
    auto hole =  getStructuringElement(1, Size(radius, radius)); // получение структурирующего элемента.
    Mat tMat; // временная матрица.
    erode(image, tMat, hole); // Ирозия, чтобы отметить центры маленьких дырок.
    dilate(tMat, resultImage, hole); // заполнение маленьких дырок.
}

holeRing::holeRing(cv::Mat &img) { 
    image = img; // заполнение поля изходного изображения.
}
