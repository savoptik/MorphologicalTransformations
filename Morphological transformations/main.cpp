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
#include "markingDefects.hpp"
using namespace std;

const string filePath = "./media/";

int main(int argc, const char * argv[]) {
    morphologicalTransformationsBase image("./media/Шестеренки.png"); // загрузка исходного сообщения.
    image.showCurrentVersion(); // вывод исходного изображения для контроля.
    holeRing closeHoloring(image.extractImage()); // создание объекта, который будет закрывать дырки.
    closeHoloring.closingHolis(97); // закрытие дыок.
    CreatorRing cr(closeHoloring.extracktIMG()); // загрузка матрицы в объект, который вырежет внутренний диск.
    cr.disconnection(280); // вырезание внутреннего диска.
    cr.showResult(); // вывод результата.
    allocationDefects ad(cr.exportResult()); // загрузка матрицы в объект, который маркирует здоровые зубцы.
    ad.labelWholeTeeth(10); // маркирование здоровых зубцов.
    ad.showResult(); // вывод результата.
    markingDefects md(image.extractImage());
    md.markingDifectTeeth(cr.extractInternalCircul(), ad.exportResultMatrix());
    md.showResultImage();
    image.exportToDisk(filePath, md.exportResult());
    return 0; // выход.
}

