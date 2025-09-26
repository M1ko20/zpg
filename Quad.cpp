//
// Created by Adam Mikoláš on 24.09.2025.
//

#include "Quad.h"

Quad::Quad() {
    static float squarePoints[] = {
        0.5f,  0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
       -0.5f,  0.5f, 0.0f,
        0.5f,  0.5f, 0.0f
   };


    points = squarePoints;
    vertexCount = 6;

    bindBuffer();
}

Quad::Quad(float* vertices, int count) {
    points = vertices;
    vertexCount = count;

    bindBuffer();
}

void Quad::draw() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}

