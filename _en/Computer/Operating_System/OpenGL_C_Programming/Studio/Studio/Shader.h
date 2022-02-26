/* Shader.h
Author: BSS9395
Update: 2022-02-26T00:27:00+08@China-Guangdong-Zhanjiang+08
Design: Studio for OpenGL
Encode: UTF-8
*/

#ifndef Shader_h
#define Shader_h

#define Header_h
#include "Common.h"
#include "System.h"
#include "Setting.h"

class Shader {
public:
    typedef Sequence<GLenum, const char*> Type;
    static inline const Type _Vertex = Type(GL_VERTEX_SHADER, "GL_VERTEX_SHADER");
    static inline const Type _Geometry = Type(GL_GEOMETRY_SHADER, "GL_GEOMETRY_SHADER");
    static inline const Type _Fragment = Type(GL_FRAGMENT_SHADER, "GL_FRAGMENT_SHADER");
    static inline const Type _Program = Type(GL_PROGRAM, "GL_PROGRAM");

public:
    GLuint _program = 0;
    GLint _location = 0;

public:
    Shader(const std::string& source, const std::string& filename = "") {
        System::Logging(__FUNCTION__);

        std::string code = "";
        code += source;
        if (0 < filename.length()) {
            FILE* file = fopen((Setting::_Shaders + filename).c_str(), "r");
            if (System::Checking(file == NULL, System::_Fatal, NULL)) {
                Exception::Excepting(true, System::_Fatal, "file == NULL", "");
            }
            fseek(file, 0, SEEK_END);
            iptr leng = ftell(file);
            rewind(file);
            iptr head = code.size();
            code.resize(head + leng);
            fread(&code[head], sizeof(char), leng, file);
        }

        _program = Compile_Shader(code);
    }

    virtual ~Shader() {
        System::Logging(__FUNCTION__);

        glDeleteProgram(_program);
    }

public:
    GLuint Compile_Shader(const std::string& code) {
        System::Logging(__FUNCTION__);
        static const char mark_begin[] = "/* @Shader:";
        static const char mark_end[] = "*/";
        static const char vertex[] = "Vertex";
        static const char geometry[] = "Geometry";
        static const char fragment[] = "Fragment";

        GLuint program = glCreateProgram();
        iptr vertex_shader = 0;
        iptr fragment_shader = 0;
        Type type = Type();
        iptr fore = 0, back = code.find(mark_begin, fore);
        while (back != std::string::npos) {
            fore = back + sizeof(mark_begin) - 1;
            if (back = code.find(vertex, fore), back != std::string::npos) {
                type = _Vertex;
                vertex_shader += 1;
                fore = back + sizeof(vertex) - 1;
            } else if (back = code.find(geometry, fore), back != std::string::npos) {
                type = _Geometry;
                fore = back + sizeof(geometry) - 1;
            } else if (back = code.find(fragment, fore), back != std::string::npos) {
                type = _Fragment;
                fragment_shader += 1;
                fore = back + sizeof(fragment) - 1;
            } else {
                Exception::Excepting(true, System::_Error, "back == std::string::npos", "");
                return 0;
            }
            if (back = code.find(mark_end, fore), back == std::string::npos) {
                Exception::Excepting(true, System::_Error, "back == std::string::npos", "");
                return 0;
            }
            fore = back + sizeof(mark_end) - 1;
            back = code.find(mark_begin, fore);

            const char* source = &code[fore];
            const GLint leng = (GLint)((back != std::string::npos) ? (iptr)(back - fore) : (iptr)(code.length() - fore));
            System::Logging("[%s]\n%s", type.At<1>(), std::string(source, leng).c_str());

            GLuint shader = glCreateShader(type.At<0>());
            glShaderSource(shader, 1, &source, &leng);
            glCompileShader(shader);
            Check_Compilation(shader, type);
            glAttachShader(program, shader);
            glDeleteShader(shader);
        }

        glLinkProgram(program);
        Check_Compilation(program, _Program);
        return program;
    }

    static GLint Check_Compilation(GLuint shader, const Type& type) {
        GLint status = GL_FALSE;
        (type.At<0>() == GL_PROGRAM)
            ? glGetProgramiv(shader, GL_LINK_STATUS, &status)
            : glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (status != GL_TRUE) {
            std::string info = type.At<1>(); info += ": ";
            iptr head = info.length();
            info.resize(1024);
            (type.At<0>() == GL_PROGRAM)
                ? glGetProgramInfoLog(shader, (GLsizei)(info.size() - head), NULL, info.data() + head)
                : glGetShaderInfoLog(shader, (GLsizei)(info.size() - head), NULL, info.data() + head);
            Exception::Excepting(true, System::_Fatal, (const char*)"status != GL_TRUE", info);
            return GL_FALSE;
        }
        return status;
    }

public:
    void Use_Program() {
        // System::Logging(__FUNCTION__);

        glUseProgram(_program);
    }

    void Update_Uniform(const std::string& uniform, const glm::vec3& vec3) {
        System::Logging("void Update_Uniform(const std::string& uniform, const glm::vec3& vec3) {");

        _location = glGetUniformLocation(_program, uniform.c_str());
        if (System::Checking(_location < 0, System::_Error, NULL)) {
            Exception::Excepting(true, System::_Error, "_location < 0", "");
            return;
        }
        glUniform3fv(_location, 1, &vec3[0]);
    }

    void Update_Uniform(const std::string& uniform, const glm::mat4& mat4, bool reverse) {
        System::Logging("void Update_Uniform(const std::string& uniform, const glm::mat4& mat4, bool reverse) {");

        _location = glGetUniformLocation(_program, uniform.c_str());
        if (System::Checking(_location < 0, System::_Error, NULL)) {
            Exception::Excepting(true, System::_Error, "_location < 0", "");
            return;
        }
        glUniformMatrix4fv(_location, 1, reverse, &mat4[0][0]);
    }
};

#endif // Shader_h
