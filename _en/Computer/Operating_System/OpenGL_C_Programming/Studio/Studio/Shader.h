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
    static inline const char _Mark[] = "/* @Shader:";

public:
    iptr _program = 0;

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
    iptr Compile_Shader(const std::string& code) {
        System::Logging(__FUNCTION__);

        iptr program = glCreateProgram();
        iptr vertex_shader = 0;
        iptr fragment_shader = 0;


        return program;
    }
};

#endif // Shader_h
