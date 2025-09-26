//
// Created by Adam Mikoláš on 23.09.2025.
//

#include "Model.h"

Model::Model() {

}

// void Model::draw() {
//     glBindVertexArray(VAO);
//     glDrawArrays(GL_TRIANGLES, 0, 3);
//     glDrawArrays(GL_TRIANGLES, 3, 3);
//
// }

void Model::bindBuffer() {
    glGenBuffers(1, &VBO); // generate the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Teď každý vertex má 6 floatů (pozice + barva)
    glBufferData(GL_ARRAY_BUFFER, vertexCount * 6 * sizeof(float), points, GL_STATIC_DRAW);

    //Vertex Array Object (VAO)
    glGenVertexArrays(1, &VAO); //generate the VAO
    glBindVertexArray(VAO); //bind the VAO
    
    // Atribut 0: pozice (3 floaty: x, y, z)
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    
    // Atribut 1: barva (3 floaty: r, g, b)
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

