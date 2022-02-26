/* Setting.h
Author: BSS9395
Update: 2022-02-26T00:27:00+08@China-Guangdong-Zhanjiang+08
Design: Studio for OpenGL
Encode: UTF-8
*/

#ifndef Setting_h
#define Setting_h

#define Header_h
#include "Common.h"
#include "System.h"

class Setting {
public:
    static inline const std::string _Root = R"(C:/Users/bss9395/source/repos/Studio/)";
    static inline const std::string _Shaders = _Root + R"(shaders/)";
    static inline const std::string _Images = _Root + R"(images/)";
    static inline const std::string _Resources = _Root + R"(resources/)";

public:
    static iptr Set() {
        System::Logging(__FUNCTION__);

        iptr ret = 0;

        int ok = _chdir(_Root.c_str());
        if (System::Checking(ok != 0, System::_Fatal, NULL)) {
            exit((int)System::_Failure);
        }
        ret += 1;

        return ret;
    }
    static inline iptr _set = Set();
};

#endif // Setting_h
