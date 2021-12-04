/* GLFW.cpp
Author: BSS9395
Update: 2021-12-04T17:27:00+08@China-Guangdong-Shenzhen+08
Design: GLFW C API
Credit: https://www.glfw.org/docs/latest/index.html
*/

/* GLFW C API
#include "glad/glad.h"
#include "GLFW/glfw3.h"


glfwCreateWindow();
glfwDefaultWindowHints();
glfwDestroyWindow();
glfwGetFramebufferSize();
glfwGetKey();
glfwGetMouseButton();
glfwGetProcAddress();
glfwGetTime();
glfwGetWindowPos();
glfwGetWindowSize();
glfwGetWindowUserPointer();
glfwInit();
glfwMakeContextCurrent();
glfwPollEvents();
glfwSetCursorPosCallback();
glfwSetErrorCallback();
glfwSetFramebufferSizeCallback();
glfwSetInputMode();
glfwSetKeyCallback();
glfwSetScrollCallback();
glfwSetWindowPos();
glfwSetWindowPosCallback();
glfwSetWindowSize();
glfwSetWindowSizeCallback();
glfwSetWindowUserPointer();
glfwSwapBuffers();
glfwSwapInterval();
glfwTerminate();
glfwWaitEvents();
glfwWindowHint();
glfwWindowShouldClose();
*/

#pragma comment(lib, "glad.lib")
#pragma comment(lib, "glfw3.lib")

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <string>

typedef intptr_t iptr;

class GLFW {
public:
    iptr _major = 4;
    iptr _minor = 3;
    iptr _width = 800;
    iptr _height = 600;
    const char *_title = "GLFW C API";
    GLFWwindow *_window = NULL;
    double _delta = 0.0;
    double _elapsed = 0.0;

public:
    GLFW() {
        glfwSetErrorCallback(Error_Callback);
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, (int)_major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, (int)_minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  /* __APPLE__ */
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        _window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
        if (_window == NULL) {
            fprintf(stderr, "%s""\n", "_window == NULL");
            exit(EXIT_FAILURE);
        }
        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, this);
        glfwSetFramebufferSizeCallback(_window, Framebuffer_Size_Callback);
        glfwSetCursorPosCallback(_window, Cursor_Pos_Callback);
        glfwSetScrollCallback(_window, Scroll_Callback);
        glfwSetKeyCallback(_window, Key_Callback);
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        int loader = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (loader == 0) {
            fprintf(stderr, "%s""\n", "loader == 0");
            exit(EXIT_FAILURE);
        }

        glfwSwapInterval(1);
    }

    virtual ~GLFW() {
        glfwDestroyWindow(_window);
        glfwTerminate();
    }

public:
    static void Error_Callback(int error_code, const char* description) {
        fprintf(stderr, "error_code = %td, description = %s""\n", (iptr)error_code, description);
    }

    static void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    static void Cursor_Pos_Callback(GLFWwindow* window, double xpos, double ypos) {
        fprintf(stdout, "xpos = %lf, ypos = %lf""\n", xpos, ypos);
    }

    static void Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset) {
        fprintf(stdout, "xoffset = %lf, yoffset = %lf""\n", xoffset, yoffset);
    }

    static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }

public:
    virtual void Get_Key() {
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(_window, true);
        }
    }

    virtual void Loop() {
        glClearColor(0.5, 0.5, 0.5, 0.5);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        glfwSwapBuffers(_window);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        while (!glfwWindowShouldClose(_window)) {
            double current = glfwGetTime();
            _delta = current - _elapsed;
            _elapsed = current;

            glClearColor(0.5, 0.5, 0.5, 0.5);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            glfwSwapBuffers(_window);

            Get_Key();
            glfwPollEvents();
        }
    }
};

int main(int argc, char *argv[]) {
    GLFW glfw;
    glfw.Loop();

    return 0;
}
