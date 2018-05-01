//
//  CreatorКing.hpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 20.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef CreatorRing_hpp
#define CreatorRing_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class CreatorRing {
public:
    CreatorRing(cv::Mat& matrix); // конструктор затянет изображение в объект.
    CreatorRing() {} // на всякий случай конструктор без параметров.
    ~CreatorRing(); // уничтожение всех ненужных объектов.
    void disconnection(int diameter); // размыкание принимает диаметр внутреннего диска.
    void showResult(); // вывод результата на экран.
    cv::Mat& exportResult() {return result;} // возврат ссылки на результирующую матрицу.
    cv::Mat& extractInternalCircul();
private:
    cv::Mat image, result, externalCircul; // исходное и результирующее изображение.
};

#endif /* CreatorRing_hpp */
