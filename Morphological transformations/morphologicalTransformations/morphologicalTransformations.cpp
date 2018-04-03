//
//  morphologicalTransformations.cpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 04.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "morphologicalTransformations.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void morphologicalTransformationsBase::showCurrentVersion() {
    auto name = namedWindow(nameWindow); // создаём имя окна.
    imshow(name, image); // выводим изображение.
    waitKey(); // ждём нажатия клавиши.
    destroyWindow(name); // уничтожаем окно.
}

morphologicalTransformationsBase::~morphologicalTransformationsBase() { 
    image.deallocate(); // освобождаем память.
}
