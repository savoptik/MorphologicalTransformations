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
    allocationDefects(cv::Mat matrix);
    allocationDefects() {}
    ~allocationDefects();
    void showResult();
    void exportResultToDisk(std::string filePath);
    cv::Mat& exportResultMatrix();
    void labelWholeTeeth(int diametr);
private:
    cv::Mat imgMatrix, resultMatrix;
};

#endif /* allocationDefects_hpp */
