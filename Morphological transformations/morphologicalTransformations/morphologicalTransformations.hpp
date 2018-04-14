//
//  morphologicalTransformations.hpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 04.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef morphologicalTransformations_hpp
#define morphologicalTransformations_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>

class morphologicalTransformationsBase {
public:
    morphologicalTransformationsBase(std::string fileName);
    morphologicalTransformationsBase() {} // просто на всякий случай пустой конструктор.
    ~morphologicalTransformationsBase(); // общий для всех диструктор.
    void showCurrentVersion(); // вывод текущего состояния изображения.
    cv::Mat& extractImage(); // Вернуть ссылку на изображение.
    void importImage(cv::Mat& img); // прямая загрузка матриц.
protected:
    cv::Mat image; // изображение.
    std::string nameWindow; // имя окна для вывода.
};

#endif /* morphologicalTransformations_hpp */
