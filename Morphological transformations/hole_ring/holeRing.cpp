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
    Mat hole(radius, radius, CV_8UC1); // матрица для будущего кольца.
    circle(hole, {radius/2, radius/2}, radius/2, 255); // создание необходимого кольца.
    Mat tMat, tMatEr; // временная матрица.
    for (int i = 0; i < 100; i++) {
        erode(image, tMat, hole); // Ирозия, чтобы отметить центры маленьких дырок.
        tMatEr = tMat + tMatEr;
    }
    auto delationIlimen = getStructuringElement(2, Size(radius, radius)); // структурирующий элемент для расширения.
    dilate(tMatEr, tMatEr, delationIlimen); // заполнение маленьких дырок.
    resultImage = image + tMatEr; // наложение результата на шестирёнки.
}

holeRing::holeRing(cv::Mat &img) { 
    image = img; // заполнение поля изходного изображения.
}

void holeRing::showCurrantImage() {
    std::string nameWindo = "Closed holes"; // имя окна.
    imshow(nameWindo, resultImage); // вывод изображения.
    waitKey(); // ожидания нажатия клавиши.
    destroyWindow(nameWindo); // уничтожение окон.
}

holeRing::~holeRing() { // освобождение памяти.
    image.deallocate();
    resultImage.deallocate();
}

