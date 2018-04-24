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
    image = matrix; // затягивание изображения внутрь объекта.
}

void CreatorRing::disconnection(int diameter) {
    Mat disk(diameter, diameter, CV_8UC1); // создание матрицы для кольца.
    circle(disk, {diameter/2, diameter/2}, diameter/2, 255); // получение окружности.
//    imshow("диск", disk); waitKey();
    Mat tMat(image.rows, image.cols, CV_8UC1); // создание матрицы, для записи результатов эрозии.
    erode(image, tMat, disk); // жрозия.
//    imshow("результат эрозии", tMat); waitKey();
    auto eliment = getStructuringElement(2, Size(diameter+7, diameter+7)); // получаем слегка увиличенный элемент для удаления центрального диска.
    dilate(tMat, tMat, eliment); // получаем центральный диск.
//    imshow("результат расширения", tMat); waitKey();
    result = image - tMat; // получаем изображение, в котором удалён центральный диск.
}

CreatorRing::~CreatorRing() {
    image.deallocate(); // уничтожение матриц.
    result.deallocate();
}

void CreatorRing::showResult() { 
    std::string name = "Результат размыкания"; // имя окна.
    namedWindow(name); // создания имени окна.
    imshow(name, result); // вывод изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow(name);// уничтожение окна.
}
