//
// Created by Adam Mikoláš on 23.09.2025.
//

#ifndef REAL_SHADERPROGRAM_H
#define REAL_SHADERPROGRAM_H

#define GLEW_NO_GLU
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

class ShaderProgram
{
    private:
    const char* vertex_shader;
    const char* fragment_shader;
    GLuint ShaderID;
    void CheckStatus();

    public:
    ShaderProgram();
    void useProgram();


};


#endif //REAL_SHADERPROGRAM_H