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

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <functional>
#include <thread>

////////////////////////////////////////////////////////////////////////////////

/* Windows */
#include <sys/types.h>
#include <sys/stat.h>
#include <direct.h>

////////////////////////////////////////////////////////////////////////////////

typedef intptr_t iptr;
typedef size_t   uptr;
typedef wchar_t  wide;

#ifndef Header_h
#define Header_h

#include "System.h"
#include "Setting.h"
#include "Application.h"

#endif // Header_h
#endif // Common_h
