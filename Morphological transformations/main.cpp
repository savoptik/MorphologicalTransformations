//
//  main.cpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 03.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include <string>
#include "morphologicalTransformations.hpp"
#include "holeRing.hpp"
#include "CreatorRing.hpp"
#include "allocationDefects.hpp"
using namespace std;

const string filePath = "./media/";

int main(int argc, const char * argv[]) {
/*    morphologicalTransformationsBase image("./media/Шестеренки.png"); // загрузка исходного сообщения.
    // umage.showCurrentVersion(); // вывод исходного изображения для контроля.
    holeRing closeHoloring(image.extractImage()); // создание объекта, который будет закрывать дырки.
    closeHoloring.closingHolis(97); // закрытие дыок.
    closeHoloring.showCurrantImage(); // вывод изображения.
    image.exportToDisk("./media/", closeHoloring.extracktIMG()); */
    morphologicalTransformationsBase st2(filePath + "result1.jpg");
    st2.showCurrentVersion();
    CreatorRing cr(st2.extractImage());
    cr.disconnection(280);
    cr.showResult();
//    st2.exportToDisk(filePath, cr.exportResult());
    allocationDefects ad(cr.exportResult());
    ad.labelWholeTeeth(10);
    ad.showResult();
    return 0; // выход.
}

