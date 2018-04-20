//
//  CreatorКing.hpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 20.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef Creator_ing_hpp
#define Creator_ing_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class CreatorКing {
public:
    CreatorКing(cv::Mat& matrix); // конструктор затянет изображение в объект.
    CreatorКing() {} // на всякий случай конструктор без параметров.
    ~CreatorКing(); // уничтожение всех ненужных объектов.
    void disconnection(int diameter); // размыкание принимает диаметр внутреннего диска.
private:
    cv::Mat image; // изображение.
};

#endif /* Creator_ing_hpp */
