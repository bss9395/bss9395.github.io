/* 01-triangles.cpp
Author: BSS9395
Update: 2022-02-26T17:30:00+08@China-Guangdong-Zhanjiang+08
Design: OpenGL_Programming_Guide example: 01-triangles
Encode: UTF-8
*/

#include "Common.h"

class Example_01 : public Window {
public:
    const char* _shader_source = R"(
/* @Shader: Vertex */
#version 450 core

layout(location = 0) in vec4 _Position;

void main() {
    gl_Position = _Position;
}

/* @Shader: Fragment */
out vec4 _Color;

void main() {
    _Color = vec4(0.0, 1.0, 1.0, 0.5);
}
)";

    float _vertices[6][3] = {
        { -0.90f, -0.90f, +0.0f }, { +0.85f, -0.90f, +0.0f }, { -0.90f, +0.85f, +0.0f },    // note: triangle 1.
        { +0.90f, -0.85f, +0.0f }, { +0.90f, +0.90f, +0.0f }, { -0.85f, +0.90f, +0.0f }     // note: triangle 2.
    };

public:
    Shader _shader = Shader(_shader_source);
    GLuint _vertex_array = 0;
    GLuint _vertex_buffer = 0;

public:
    virtual void Setup() override {
        System::Logging(__FUNCTION__);
        Window::Setup();

        glEnable(GL_DEPTH_TEST);

        glCreateVertexArrays(1, &_vertex_array);
        glCreateBuffers(1, &_vertex_buffer);
        glBindVertexArray(_vertex_array);
        glBindBuffer(GL_ARRAY_BUFFER, _vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), &_vertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    }

    virtual void Render() override {
        // System::Logging(__FUNCTION__);
        glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        _shader.Use_Program();
        glBindVertexArray(_vertex_array);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(_vertices) / sizeof(_vertices[0]));
    }
};

int main(int argc, char* argv[]) {
    Application application = Application();
    Window* window = new Example_01();
    window->Loop();

    return 0;
}
