//
//  holeRing.hpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 10.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef holeRing_hpp
#define holeRing_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class holeRing {
public:
    holeRing(cv::Mat& img); // конструткор заполнит поле исходного изображения.
    holeRing() {} // на всякий случай конструктор без параметров.
    cv::Mat& extracktIMG(); // метод возвращает ссылку на исходный элемент.
    void closingHolis(int radius); // метод закрывает дырки с заданным радиусом.
    void showCurrantImage(); // вывод результирующего изображения.
    ~holeRing(); // диструктор.
protected:
    cv::Mat image; // исходное изображение.
    cv::Mat resultImage; // результирующее изображение.
};

#endif /* holeRing_hpp */
