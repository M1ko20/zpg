//
// Created by Adam Mikoláš on 24.09.2025.
//

#include "Triangle.h"

Triangle::Triangle() {
    static float trianglePoints[] = {
        1.5f, 1.5f, 0.0f,
        0.5f, -1.5f, 0.0f,
       -0.5f, -1.5f, 0.0f
    };

    points = trianglePoints;
    vertexCount = 3;

    bindBuffer();
}

Triangle::Triangle(float* vertices, int count) {
    points = vertices;
    vertexCount = count;

    bindBuffer();
}


void Triangle::draw(){
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

}