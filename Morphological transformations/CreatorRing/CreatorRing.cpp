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
    matrix.copyTo(image); // затягивание изображения.
}

void CreatorRing::disconnection(int diameter) {
    Mat disk(diameter, diameter, CV_8UC1); // матрица для кольца.
    circle(disk, {diameter/2, diameter/2}, diameter/2, 255); // создание кольца.
    Mat tMat(image.rows, image.cols, CV_8UC1); // временная матрица.
    erode(image, tMat, disk); // эрозия созданным кольцом.
    Mat erodMat; // матрица с ирозией.
    tMat.copyTo(erodMat); // копируем результат ирозии в матрицу.
    auto eliment = getStructuringElement(2, Size(diameter+7, diameter+7)); // структурирующий элемент для расширения.
    dilate(tMat, tMat, eliment); // расширение созданным выше структурирующим элементом.
    result = image - tMat; // вырезание внутреннего диска из шестерёнок.
    auto eliment2 = getStructuringElement(2, Size(diameter+7+10, diameter+7+10)); // структурирующий элемент для получения внутреннего диска, увиличенного на длинну зубца.
    dilate(erodMat, externalCircul, eliment2); // расширение.
    externalCircul =externalCircul - tMat; // получение кольца.
}

CreatorRing::~CreatorRing() { // освобождение памяти.
    image.deallocate();
    result.deallocate();
    externalCircul.deallocate();
}

void CreatorRing::showResult() { 
    std::string name = "Результат размыкания"; // имя окна.
    namedWindow(name); // создание окна.
    imshow(name, result); // вывод изображения на экран.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow(name); // уничтожение окна.
}

cv::Mat &CreatorRing::extractInternalCircul() { 
    return externalCircul; // возврат ссылки на матрицу, хранящую внешние кольца.
}
