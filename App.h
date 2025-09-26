//
// Created by Adam Mikoláš on 23.09.2025.
//

#ifndef REAL_APP_H
#define REAL_APP_H
#define GLEW_NO_GLU
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "Model.h"
#include "ShaderProgram.h"

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void window_focus_callback(GLFWwindow* window, int focused);
static void window_iconify_callback(GLFWwindow* window, int iconified);
static void window_size_callback(GLFWwindow* window, int width, int height);
static void cursor_callback(GLFWwindow* window, double x, double y);
static void button_callback(GLFWwindow* window, int button, int action, int mode);


class App {
public:
    App();
    void initialization();
    void createShaders();
    void createModels();
    void run();

private:
    GLFWwindow* window;
    float ratio;
    Model* models[2];
    ShaderProgram* shaderProgram;
};


#endif //REAL_APP_H