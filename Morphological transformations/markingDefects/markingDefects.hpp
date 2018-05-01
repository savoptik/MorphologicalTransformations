//
//  markingDefects.hpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 24.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef markingDefects_hpp
#define markingDefects_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class markingDefects {
public:
    markingDefects(cv::Mat& matrix); // конструктор затянет матрицу из внешнего мира.
    markingDefects() {} // конструктор без параметров.
    void showResultImage(); // вывод результирующего изображения на экран.
    cv::Mat& exportResult(); // возврат ссылки на результирующее изображение.
    void markingDifectTeeth(cv::Mat externalCircul, cv::Mat circulTeeth); // маркирование диффектных зубцов.
private:
    cv::Mat imgMatrix, resultMatrix, teethDisk;
};
#endif /* markingDefects_hpp */
