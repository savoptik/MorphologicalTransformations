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
    morphologicalTransformationsBase st2(filePath + "result1.jpg"); // загрузка шестерёнки с закрытыми внутренними отверстиями.
    st2.showCurrentVersion(); // вывод изображения для контроля.
    CreatorRing cr(st2.extractImage()); // загрузка матрицы в объект, который вырежет внутренний диск.
    cr.disconnection(280); // вырезание внутреннего диска.
    cr.showResult(); // вывод результата.
    allocationDefects ad(cr.exportResult()); // загрузка матрицы в объект, который маркирует здоровые зубцы.
    ad.labelWholeTeeth(10); // маркирование здоровых зубцов.
    ad.showResult(); // вывод результата.
    return 0; // выход.
}

