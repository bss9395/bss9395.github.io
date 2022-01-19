/* X-Z_Coordinate.cpp
Author: BSS9395
Update: 2021-12-29T22:47:00+08@China-Guangdong-Shenzhen+08
Design: X-Z Coordinate
Encode: UTF-8
*/

#pragma comment(lib, "glad.lib")
#pragma comment(lib, "glfw3.lib")

#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>

#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////////////

std::string _Buffer = std::string(1024, '\0');
int _Width_sc = 800;
int _Height_sc = 600;
GLFWwindow *_Window = NULL;
unsigned int _Texture = 0;
unsigned int _VAO_Cube = 0;
unsigned int _VBO_Cube = 0;
unsigned int _VAO_Axis = 0;
unsigned int _VBO_Axis = 0;
unsigned int _PS_Cube = 0;
unsigned int _PS_Axis = 0;

#define RESTART
// ![Cube_Order.svg](figures/Cube_Order.svg)
float _Cube[5 * 24] = { // GL_TRIANGLE_STRIP
    // X-Z coordinate
    // -X <= -Y <= -Z <= +Z <= +Y <= +X
    // +X, CCW => CW, upward
    +0.5, -0.5, -0.5, 0.0, 0.0,
    +0.5, +0.5, -0.5, 1.0, 0.0,
    +0.5, -0.5, +0.5, 0.0, 1.0,
    +0.5, +0.5, +0.5, 1.0, 1.0,
    RESTART
    // +Y, CCW => CW, upward
    +0.5, +0.5, -0.5, 0.0, 0.0,
    -0.5, +0.5, -0.5, 1.0, 0.0,
    +0.5, +0.5, +0.5, 0.0, 1.0,
    -0.5, +0.5, +0.5, 1.0, 1.0,
    RESTART
    // +Z, CCW => CW, outward
    +0.5, +0.5, +0.5, 0.0, 0.0,
    -0.5, +0.5, +0.5, 1.0, 0.0,
    +0.5, -0.5, +0.5, 0.0, 1.0,
    -0.5, -0.5, +0.5, 1.0, 1.0,
    RESTART
    // -Z, CCW => CW, outward
    -0.5, +0.5, -0.5, 0.0, 0.0,
    +0.5, +0.5, -0.5, 1.0, 0.0,
    -0.5, -0.5, -0.5, 0.0, 1.0,
    +0.5, -0.5, -0.5, 1.0, 1.0,
    RESTART
    // -Y, CCW => CW, upward
    -0.5, -0.5, -0.5, 0.0, 0.0,
    +0.5, -0.5, -0.5, 1.0, 0.0,
    -0.5, -0.5, +0.5, 0.0, 1.0,
    +0.5, -0.5, +0.5, 1.0, 1.0,
    RESTART
    // -X, CCW => CW, upward
    -0.5, +0.5, -0.5, 0.0, 0.0,
    -0.5, -0.5, -0.5, 1.0, 0.0,
    -0.5, +0.5, +0.5, 0.0, 1.0,
    -0.5, -0.5, +0.5, 1.0, 1.0
};

float _Axis[6 * 3] = {
    // X-Z coordinate
    // +X
    +0.0, +0.0, +0.0, +1.0, +0.0, +0.0,
    // +Y
    +0.0, +0.0, +0.0, +0.0, +1.0, +0.0,
    // +Z
    +0.0, +0.0, +0.0, +0.0, +0.0, +1.0
};

const char *_VS = R"(
/* @Shader: Vertex */
#version 330 core

uniform mat4 _Model;
uniform mat4 _View;
uniform mat4 _Projection;
layout(location = 0) in vec3 _vs_Position;
layout(location = 1) in vec2 _vs_Mapping;
out vec2 _fs_Mapping;

void main() {
    gl_Position = _Projection * _View * _Model * vec4(_vs_Position, 1.0f);
    _fs_Mapping = _vs_Mapping;
}
)";

const char *_FS_Cube = R"(
/* @Shader: Fragment */
#version 330 core

uniform sampler2D _Texture;
in vec2 _fs_Mapping;
out vec4 _fs_Color;

void main() {
    _fs_Color = texture(_Texture, _fs_Mapping);
}
)";

const char *_FS_Axis = R"(
/* @Shader: Fragment */
#version 330 core

out vec4 _fs_Color;

void main() {
    _fs_Color = vec4(0.0, 1.0, 0.0, 1.0);  // color green
}
)";

void Framebuffer_Size_Callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void On_Key(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(int argc, char *argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
    _Window = glfwCreateWindow(_Width_sc, _Height_sc, "X-Z Coordinate", NULL, NULL);
    glfwMakeContextCurrent(_Window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "%s""\n", "!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)");
        glfwTerminate();
    }
    glfwSetFramebufferSizeCallback(_Window, Framebuffer_Size_Callback);

    ////////////////////////////////////

    glGenVertexArrays(1, &_VAO_Cube);
    glGenBuffers(1, &_VBO_Cube);
    glBindVertexArray(_VAO_Cube);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO_Cube);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_Cube), _Cube, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenTextures(1, &_Texture);
    glBindTexture(GL_TEXTURE_2D, _Texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width = 0;
    int height = 0;
    int channel = 0;
    stbi_set_flip_vertically_on_load(true); // screen coordinate => graphics coordinate
    unsigned char *data = stbi_load("resources/Face.png", &width, &height, &channel, 0);
    if (data != NULL) {
        GLenum format = 0;
        if (channel == 1) {
            format = GL_RED;
        } else if (channel == 3) {
            format = GL_RGB;
        } else if (channel == 4) {
            format = GL_RGBA;
        }
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);

    glGenVertexArrays(1, &_VAO_Axis);
    glGenBuffers(1, &_VBO_Axis);
    glBindVertexArray(_VAO_Axis);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO_Axis);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_Axis), _Axis, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    ////////////////////////////////////

    int success = 0;
    unsigned int vs_cube = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs_cube, 1, &_VS, NULL);
    glCompileShader(vs_cube);

    unsigned int fs_cube = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs_cube, 1, &_FS_Cube, NULL);
    glCompileShader(fs_cube);
    _PS_Cube = glCreateProgram();
    glAttachShader(_PS_Cube, vs_cube);
    glAttachShader(_PS_Cube, fs_cube);
    glLinkProgram(_PS_Cube);
    glGetProgramiv(_PS_Cube, GL_LINK_STATUS, &success);
    if (success == 0) {
        glGetProgramInfoLog(_PS_Cube, (GLsizei)_Buffer.size(), NULL, _Buffer.data());
        fprintf(stderr, "%s""\n", _Buffer.data());
        glfwTerminate();
    }

    unsigned int fs_axis = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs_axis, 1, &_FS_Axis, NULL);
    glCompileShader(fs_axis);
    _PS_Axis = glCreateProgram();
    glAttachShader(_PS_Axis, vs_cube);
    glAttachShader(_PS_Axis, fs_axis);
    glLinkProgram(_PS_Axis);
    glGetProgramiv(_PS_Axis, GL_LINK_STATUS, &success);
    if (success == 0) {
        glGetProgramInfoLog(_PS_Axis, (GLsizei)_Buffer.size(), NULL, _Buffer.data());
        fprintf(stderr, "%s""\n", _Buffer.data());
        glfwTerminate();
    }

    glDeleteShader(vs_cube);
    glDeleteShader(fs_cube);
    glDeleteShader(fs_axis);

    ////////////////////////////////////

    // glEnable(GL_PRIMITIVE_RESTART); // use glPrimitiveRestartIndex() instead.
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glLineWidth(5.0f);
    GLfloat range[2] = { 0.0f, 0.0f };
    glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, range);
    fprintf(stderr, "%f, %f \n", range[0], range[1]);
    glGetFloatv(GL_LINE_WIDTH_GRANULARITY, range);
    fprintf(stderr, "%f, %f""\n", range[0], range[1]);
    glGetFloatv(GL_LINE_WIDTH, range);
    fprintf(stderr, "%f, %f""\n", range[0], range[1]);

    ////////////////////////////////////

    // X-Y coordinate <= X-Z coordinate.
    glm::mat3 coordinate = glm::rotate(glm::mat4(1.0), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    while (!glfwWindowShouldClose(_Window)) {
        On_Key(_Window);

        glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 model = coordinate;                                // X-Y coordinate <= X-Z coordinate.
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0)); // rotate around +Z axis

        glm::vec3 eye = coordinate * glm::vec3(+2.0f, +2.0f, +2.0f); // camera in X-Z coordinate.
        glm::vec3 center = coordinate * glm::vec3(0.0f, 0.0f, 0.0f); // object in X-Z coordinate.
        glm::vec3 pole = coordinate * glm::vec3(0.0f, 0.0f, 1.0f);   // pole in X-Z coordinate.
        glm::vec3 right = glm::cross(center - eye, pole);
        glm::vec3 up = glm::cross(right, center - eye);
        glm::mat4 view = glm::lookAt(eye, center, up);

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)_Width_sc / (float)_Height_sc, 0.1f, 100.0f);

        glUseProgram(_PS_Cube);
        glUniformMatrix4fv(glGetUniformLocation(_PS_Cube, "_Model"), 1, GL_FALSE, &model[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(_PS_Cube, "_View"), 1, GL_FALSE, &view[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(_PS_Cube, "_Projection"), 1, GL_FALSE, &projection[0][0]);
        glUniform1i(glGetUniformLocation(_PS_Cube, "_Texture"), 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, _Texture);
        glBindVertexArray(_VAO_Cube);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 24);  // note: 24 indexes for GL_TRIANGLE_STRIP, 36 indexes for GL_TRIANGLES.
        // note: use glPrimitiveRestartIndex() and glDrawElements() instead.
        // note: for more detail information, please check 《OpenGL Programming Guide(Ninth Edition)》 sample 3.8.

        ////////////////////////////////

        glUseProgram(_PS_Axis);
        model = coordinate;
        glUniformMatrix4fv(glGetUniformLocation(_PS_Axis, "_Model"), 1, GL_FALSE, &model[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(_PS_Axis, "_View"), 1, GL_FALSE, &view[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(_PS_Axis, "_Projection"), 1, GL_FALSE, &projection[0][0]);

        glBindVertexArray(_VAO_Axis);
        glDrawArrays(GL_LINES, 0, 6);

        glfwSwapBuffers(_Window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &_VAO_Cube);
    glDeleteVertexArrays(1, &_VAO_Axis);
    glDeleteBuffers(1, &_VBO_Cube);
    glDeleteBuffers(1, &_VBO_Axis);
    glDeleteProgram(_PS_Cube);
    glDeleteProgram(_PS_Axis);
    glfwDestroyWindow(_Window);
    glfwTerminate();
    return 0;
}
