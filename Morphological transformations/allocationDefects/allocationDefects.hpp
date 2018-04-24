//
//  allocationDefects.hpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 24.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef allocationDefects_hpp
#define allocationDefects_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class allocationDefects {
public:
    allocationDefects(cv::Mat matrix); // конструктор.
    allocationDefects() {} // конструктор без параметров.
    ~allocationDefects(); // диструктор, который освободит память.
    void showResult(); // вывод результата.
    void exportResultToDisk(std::string filePath); // вывод изображения на диск.
    cv::Mat& exportResultMatrix(); // возврат ссылки на результирующую матрицу.
    void labelWholeTeeth(int diametr); // маркирование кружочками целых зубцов.
private:
    cv::Mat imgMatrix, resultMatrix; // исходное и результирующее изображение.
};

#endif /* allocationDefects_hpp */
