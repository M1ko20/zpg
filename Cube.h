//
// Created by Adam Mikoláš on 27.09.2025.
//

#ifndef REAL_CUBE_H
#define REAL_CUBE_H
#include "Model.h"


class Cube : public Model {
    public:
    Cube();
    Cube(float* vertices, int count);
    void draw() override;
};


#endif //REAL_CUBE_H