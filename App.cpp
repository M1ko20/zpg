//
// Created by Adam Mikoláš on 23.09.2025.
//

#include "App.h"

#include "Quad.h"
#include "Triangle.h"
#include "Cube.h"

static void error_callback(int error, const char* description) { fputs(description, stderr); }

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

static void window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

static void window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

static void window_size_callback(GLFWwindow* window, int width, int height) {
    printf("resize %d, %d \n", width, height);
    glViewport(0, 0, width, height);
}

static void cursor_callback(GLFWwindow* window, double x, double y) { printf("cursor_callback \n"); }

static void button_callback(GLFWwindow* window, int button, int action, int mode) {
    if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

App::App()
{
    //shaderProgram = nullptr;
    window = nullptr;
    //model = nullptr;
    ratio = 0;
}


void App::initialization()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_callback);
    glfwSetMouseButtonCallback(window, button_callback);
    glfwSetWindowFocusCallback(window, window_focus_callback);
    glfwSetWindowIconifyCallback(window, window_iconify_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);

    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // get version info
    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("Vendor %s\n", glGetString(GL_VENDOR));
    printf("Renderer %s\n", glGetString(GL_RENDERER));
    printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    printf("Using GLFW %i.%i.%i\n", major, minor, revision);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);
}

void App::createShaders() {


    const char*  vertex_shader =
     "#version 330\n"
     "layout(location=0) in vec3 vp;"
     "layout(location=1) in vec3 vn;"
     "out vec3 color;"
     "void main () {"
     "     gl_Position = vec4 (vp, 1.0);"
     "     color = vn;"
     "}";


    const char* fragment_shader =
    "#version 330\n"
    "in vec3 color;"
    "out vec4 fragColor;"
    "void main () {"
    "     fragColor = vec4 (0.0,1.0,1.0, 1.0);"
    "}";


    shaderPrograms[0] = new ShaderProgram();
    shaderPrograms[1] = new ShaderProgram(vertex_shader, fragment_shader);
}

void App::createModels() {
    static float trianglePoints[] = {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f
    };

    static float quadPoints[] = {
        0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.5f,  0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         1.5f,  1.5f, 0.0f,   0.0f, 0.0f, 1.0f,
         1.5f,  1.5f, 0.0f,   0.0f, 0.0f, 1.0f,
         0.5f,  1.5f, 0.0f,   1.0f, 1.0f, 0.0f,
         0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f

    };
    models[0] = new Triangle(trianglePoints, 3);
    models[1] = new Quad(quadPoints, 6);
}

void App::run() {
    while (!glfwWindowShouldClose(window)) {
        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        shaderPrograms[0]->useProgram();
        models[0]->draw();
        shaderPrograms[1]->useProgram();
        models[1]->draw();

        // update other events like input handling
        glfwPollEvents();
        // put the stuff we've been drawing onto the display
        glfwSwapBuffers(window);
    }
}
