/* X-Z_Coordinate.cpp
Author: BSS9395
Update: 2021-12-29T18:23:00+08@China-Guangdong-Shenzhen+08
Design: X-Z Coordinate
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
static int _Width_sc = 800;
static int _Height_sc = 600;
GLFWwindow *_Window = NULL;
unsigned int _VAO = 0;
unsigned int _VBO = 0;
unsigned int _Texture = 0;
unsigned int _Program = 0;

float _Vertices[5 * 24] = {
    // ![Cube_Order.svg](figures/Cube_Order.svg)
    // X-Z coordinate
    // -X <= -Y <= -Z <= +Z <= +Y <= +X
    // +X, CCW => CW, upward
    +0.5, -0.5, -0.5, 0.0, 0.0,
    +0.5, +0.5, -0.5, 1.0, 0.0,
    +0.5, -0.5, +0.5, 0.0, 1.0,
    +0.5, +0.5, +0.5, 1.0, 1.0,
    // +Y, CCW => CW, upward
    +0.5, +0.5, -0.5, 0.0, 0.0,
    -0.5, +0.5, -0.5, 1.0, 0.0,
    +0.5, +0.5, +0.5, 0.0, 1.0,
    -0.5, +0.5, +0.5, 1.0, 1.0,
    // +Z, CCW => CW, outward
    +0.5, +0.5, +0.5, 0.0, 0.0,
    -0.5, +0.5, +0.5, 1.0, 0.0,
    +0.5, -0.5, +0.5, 0.0, 1.0,
    -0.5, -0.5, +0.5, 1.0, 1.0,
    // -Z, CCW => CW, outward
    -0.5, +0.5, -0.5, 0.0, 0.0,
    +0.5, +0.5, -0.5, 1.0, 0.0,
    -0.5, -0.5, -0.5, 0.0, 1.0,
    +0.5, -0.5, -0.5, 1.0, 1.0,
    // -Y, CCW => CW, upward
    -0.5, -0.5, -0.5, 0.0, 0.0,
    +0.5, -0.5, -0.5, 1.0, 0.0,
    -0.5, -0.5, +0.5, 0.0, 1.0,
    +0.5, -0.5, +0.5, 1.0, 1.0,
    // -X, CCW => CW, upward
    -0.5, +0.5, -0.5, 0.0, 0.0,
    -0.5, -0.5, -0.5, 1.0, 0.0,
    -0.5, +0.5, +0.5, 0.0, 1.0,
    -0.5, -0.5, +0.5, 1.0, 1.0
};

const char *_Vertex_Shader = R"(
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

const char *_Fragment_Shader = R"(
/* @Shader: Fragment */
#version 330 core

uniform sampler2D _Texture;

in vec2 _fs_Mapping;

out vec4 _fs_Color;

void main() {
    _fs_Color = texture(_Texture, _fs_Mapping);
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
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // #ifdef __APPLE__
    glfwWindowHint(GLFW_SAMPLES, 4);
    _Window = glfwCreateWindow(_Width_sc, _Height_sc, "X-Z Coordinate", NULL, NULL);
    glfwMakeContextCurrent(_Window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "%s""\n", "!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)");
        glfwTerminate();
    }
    glfwSetFramebufferSizeCallback(_Window, Framebuffer_Size_Callback);

    ////////////////////////////////////

    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
    glBindVertexArray(_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_Vertices), _Vertices, GL_STATIC_DRAW);
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

    ////////////////////////////////////

    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &_Vertex_Shader, NULL);
    glCompileShader(vertex_shader);
    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &_Fragment_Shader, NULL);
    glCompileShader(fragment_shader);
    _Program = glCreateProgram();
    glAttachShader(_Program, vertex_shader);
    glAttachShader(_Program, fragment_shader);
    glLinkProgram(_Program);
    int success = 0;
    glGetProgramiv(_Program, GL_LINK_STATUS, &success);
    if (success == 0) {
        glGetProgramInfoLog(_Program, (GLsizei)_Buffer.size(), NULL, _Buffer.data());
        fprintf(stderr, "%s""\n", _Buffer.data());
        glfwTerminate();
    }
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    ////////////////////////////////////

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    glUseProgram(_Program);
    glUniform1i(glGetUniformLocation(_Program, "_Texture"), 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _Texture);

    // X-Y coordinate <= X-Z coordinate.
    glm::mat4 coord = glm::rotate(glm::mat4(1.0), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    while (!glfwWindowShouldClose(_Window)) {
        On_Key(_Window);

        glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 model = glm::mat4(1.0f);
        model = coord * model;                              // X-Y coordinate <= X-Z coordinate.
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0, 0.0, 1.0)); // rotate around +Z axis

        glm::vec3 camera = glm::vec3(+2.0f, +2.0f, -2.0f);  // camera in X-Y coordinate
        glm::vec3 pole = glm::vec3(0.0, 1.0, 0.0);
        glm::vec3 right = glm::cross(pole, camera);
        glm::vec3 up = glm::cross(camera, right);
        glm::mat4 view = glm::lookAt(camera, glm::vec3(0.0f, 0.0f, 0.0f), glm::normalize(up));

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)_Width_sc / (float)_Height_sc, 0.1f, 100.0f);
        glUniformMatrix4fv(glGetUniformLocation(_Program, "_Model"), 1, GL_FALSE, &model[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(_Program, "_View"), 1, GL_FALSE, &view[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(_Program, "_Projection"), 1, GL_FALSE, &projection[0][0]);

        glBindVertexArray(_VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 24);

        glfwSwapBuffers(_Window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &_VAO);
    glDeleteBuffers(1, &_VBO);
    glDeleteProgram(_Program);
    glfwDestroyWindow(_Window);
    glfwTerminate();
    return 0;
}
