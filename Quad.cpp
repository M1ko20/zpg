//
// Created by Adam Mikoláš on 24.09.2025.
//

#include "Quad.h"

Quad::Quad() {
    // Každý vertex má 6 floatů: x, y, z, r, g, b
    static float squarePoints[] = {
        // Pozice (x, y, z)     // Barva (r, g, b)
         0.5f,  0.5f, 0.0f,     1.0f, 1.0f, 0.0f,  // Pravý horní - žlutá
         0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 1.0f,  // Pravý dolní - cyan
        -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 1.0f,  // Levý dolní - magenta
        -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 1.0f,  // Levý dolní - magenta
        -0.5f,  0.5f, 0.0f,     0.5f, 0.5f, 0.5f,  // Levý horní - šedá
         0.5f,  0.5f, 0.0f,     1.0f, 1.0f, 0.0f   // Pravý horní - žlutá
    };

    points = squarePoints;
    vertexCount = 6;

    bindBuffer();
}

void Quad::draw() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 3, 3);
}

