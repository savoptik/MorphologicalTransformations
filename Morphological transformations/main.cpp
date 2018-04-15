//
//  main.cpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 03.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include "morphologicalTransformations.hpp"
#include "holeRing.hpp"

int main(int argc, const char * argv[]) {
    morphologicalTransformationsBase image("./media/Шестеренки.png"); // загрузка исходного сообщения.
    image.showCurrentVersion(); // вывод исходного изображения для контроля.
    holeRing closeHoloring(image.extractImage()); // создание объекта, который будет закрывать дырки.
    closeHoloring.closingHolis(100); // закрытие дыок.
    closeHoloring.showCurrantImage(); // вывод изображения.
    return 0; // выход.
}
