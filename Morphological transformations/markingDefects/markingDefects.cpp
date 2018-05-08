//
//  markingDefects.cpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 24.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "markingDefects.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

markingDefects::markingDefects(cv::Mat &matrix) { 
    matrix.copyTo(imgMatrix); // затягиваем изображение.
}

cv::Mat &markingDefects::exportResult() {
    return resultMatrix; // возврат ссылки на результирующее изображение.
}

void markingDefects::showResultImage() { 
    std::string name = "result marking"; // строка с именем окна.
    namedWindow(name); // добавляем окно.
    imshow(name, resultMatrix); // выводим изображение.
    waitKey(); // ожидаем нажатия клавиши.
    destroyWindow(name); // уничтожение окна.
}

void markingDefects::markingDifectTeeth(cv::Mat externalCircul, cv::Mat circulTeeth) { 
    teethDisk = externalCircul - circulTeeth; // вычитаем из внешнего диска диск здоровых зубцов.
    resultMatrix = teethDisk; // накладываем получившиеся метки на исходное изображение.
}

