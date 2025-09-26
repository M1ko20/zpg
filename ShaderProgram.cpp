//
// Created by Adam Mikoláš on 23.09.2025.
//

#include "ShaderProgram.h"

void ShaderProgram::CheckStatus() {
    GLint status;
    glGetProgramiv(ShaderID, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetProgramiv(ShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(ShaderID, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
    }
}

ShaderProgram::ShaderProgram() {

    vertex_shader =
 "#version 330\n"
 "layout(location=0) in vec3 vp;"
 "layout(location=1) in vec3 vn;"
 "out vec3 color;"
 "void main () {"
 "     gl_Position = MVP * vec4 (vp, 1.0);"
 "     color = vn;"
 "}";


    fragment_shader =
    "#version 330\n"
    "in vec3 color;"
    "out vec4 fragColor;"
    "void main () {"
    "     gl_FragColor = vec4 (color, 1.0);"
    "}";


    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex_shader, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
    glCompileShader(fragmentShader);

    ShaderID = glCreateProgram();
    glAttachShader(ShaderID, fragmentShader);
    glAttachShader(ShaderID, vertexShader);
    glLinkProgram(ShaderID);
}

void ShaderProgram::useProgram() {
    glUseProgram(ShaderID);
}
