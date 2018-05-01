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
    imgMatrix.deallocate(); // освобождение памяти.
    resultMatrix.deallocate();
}

allocationDefects::allocationDefects(cv::Mat matrix) { 
    matrix.copyTo(imgMatrix); // затягивание матрицы.
}

cv::Mat &allocationDefects::exportResultMatrix() { 
    return resultMatrix; // возврат ссылки на матрицу.
}

void allocationDefects::exportResultToDisk(std::string filePath) { 
    imwrite(filePath + "result3.jpg", resultMatrix); // запись результирующего изображения на диск.
}

void allocationDefects::showResult() { 
    std::string name = "выделение дефектов"; // имя окна.
    namedWindow(name); // создание окна.
    imshow(name, resultMatrix); // вывод изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow(name); // уничтожение изображения.
}

void allocationDefects::labelWholeTeeth(int diametr) { 
    Mat teethCirkul(diametr, diametr, CV_8UC1); // пустая матрица для кольца.
    circle(teethCirkul, {diametr/2, diametr/2}, diametr/2, 255); // создание кольца.
    dilate(imgMatrix, resultMatrix, teethCirkul); // расширение элементом.
}

