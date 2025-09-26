//
// Created by Adam Mikoláš on 24.09.2025.
//

#include "Triangle.h"

Triangle::Triangle() {
    // Každý vertex má 6 floatů: x, y, z, r, g, b
    static float trianglePoints[] = {
        // Pozice (x, y, z)    // Barva (r, g, b)
         0.0f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,  // Vrchní vertex - červený
        -0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,  // Levý dolní vertex - zelený
         0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f   // Pravý dolní vertex - modrý
    };

    points = trianglePoints;
    vertexCount = 3;

    bindBuffer();
}


void Triangle::draw(){
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}