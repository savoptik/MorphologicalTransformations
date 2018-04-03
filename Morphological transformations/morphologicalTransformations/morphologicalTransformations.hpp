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
    morphologicalTransformationsBase() {} // просто на всякий случай пустой конструктор.
    ~morphologicalTransformationsBase(); // общий для всех диструктор.
    void showCurrentVersion(); // вывод текущего состояния изображения.
protected:
    cv::Mat image; // изображение.
    std::string nameWindow; // имя окна для вывода.
};

#endif /* morphologicalTransformations_hpp */
