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
    holeRing(cv::Mat& img, int radius);
    holeRing() {}
    cv::Mat& extracktIMG();
    void closingHolis();
protected:
    cv::Mat hole;
    cv::Mat image;
};

#endif /* holeRing_hpp */
