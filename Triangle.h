//
// Created by Adam Mikoláš on 24.09.2025.
//

#ifndef REAL_TRIANGLE_H
#define REAL_TRIANGLE_H
#include "Model.h"


class Triangle: public Model{
public:
    Triangle();
    Triangle(float* vertices, int count);
    void draw() override;
};


#endif //REAL_TRIANGLE_H