//
// Created by Adam Mikoláš on 23.09.2025.
//

#ifndef REAL_MODEL_H
#define REAL_MODEL_H
#include <GL/glew.h>

class Model
{
protected:
    GLuint VAO;
    GLuint VBO;
    float* points;
    int vertexCount;
    void bindBuffer();


public:
    Model();
    virtual void draw() = 0;
    virtual ~Model() = default;
};


#endif //REAL_MODEL_H