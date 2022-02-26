/* Common.h
Author: BSS9395
Update: 2022-02-26T00:27:00+08@China-Guangdong-Zhanjiang+08
Design: Studio for OpenGL
Encode: UTF-8
*/

#ifndef Common_h
#define Common_h

#pragma comment(lib, "glad.lib")
#pragma comment(lib, "glfw3.lib")

////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION

#include <glm/glm.hpp>                         // note: header only.
#include <glm/ext.hpp>                         // note: header only.
#include <glm/ext/quaternion_geometric.hpp>    // note: header only.
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>                     // note: header only.

////////////////////////////////////////////////////////////////////////////////

#include <cstdarg>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <type_traits>
#include <typeinfo>
#include <vector>

////////////////////////////////////////////////////////////////////////////////

/* Windows */
#include <sys/types.h>
#include <sys/stat.h>
#include <direct.h>

////////////////////////////////////////////////////////////////////////////////

#ifndef Header_h
#define Header_h

#include "System.h"
#include "Setting.h"
#include "Shader.h"
#include "Application.h"

#endif // Header_h
#endif // Common_h
