/* Application.h
Author: BSS9395
Update: 2022-02-26T00:27:00+08@China-Guangdong-Zhanjiang+08
Design: Studio for OpenGL
Encode: UTF-8
*/

#ifndef Application_h
#define Application_h

#define Header_h
#include "Common.h"
#include "System.h"

class Window {
public:
    static inline std::vector<Window*> _Windows = std::vector<Window*>();
    std::thread _thread = std::thread();

public:
    static inline std::string _Icon = "view_in_ar.png";
    static inline std::string _Title = "Window";
    static inline iptr _Width = 800;
    static inline iptr _Height = 600;

public:
    // Camera _camera = Camera();
    double _elapsed = 0.0;
    double _delta = 0.0;
    GLFWmonitor* _monitor = nullptr;
    GLFWwindow* _window = nullptr;
    std::string _title = std::string();
    iptr _width = 0;
    iptr _height = 0;

public:
    Window(const iptr width = _Width, const iptr height = _Height, const std::string& title = _Title) {
        System::Logging(__FUNCTION__);

        _width = width;
        _height = height;
        _title = title;

        ////////////////////////////////

        //glfwWindowHint(GLFW_AUTO_ICONIFY, GLFW_FALSE);              // note: ignored for windowed mode windows.
        //glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_TRUE);              // note: ignored for windowed mode windows. centered over newly created full screen windows.
        //glfwWindowHint(GLFW_DECORATED, GL_FALSE);                   // note: ignored for full screen windows. // will not be resizable
        //glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);               // note: always == GLFW_TRUE
        //glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);                   // note: floating above other regular windows.
        //glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);                    // note: windowed mode window will be given input focus when created.
        //glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);              // note: be given input focus when glfwShowWindow is called.
        //glfwWindowHint(GLFW_ICONIFIED, GL_TRUE);                    // note: no effect.
        //glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);                  // note: ignored for full screen windows.
        //glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);          // note: ignored for windowed mode windows, the highest available refresh rate will be used.
        //glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);                    // note: take window aspect ratio into account.
        //glfwWindowHint(GLFW_SAMPLES, 4);                            // note: the desired number of samples to use for multisampling.
        //glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);           // note: where screen coordinates and pixels always map 1:1 such as Windows and X11.
        //glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);               // note: default == GLFW_FALSE
        //glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);    // note: not affect window decorations.
        //glfwWindowHint(GLFW_VISIBLE, GL_FALSE);                     // note: ignored for full screen windows.

        ////////////////////////////////

        _monitor = glfwGetPrimaryMonitor();
        //const GLFWvidmode* mode = glfwGetVideoMode(_monitor);
        //glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        //glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        //glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        //glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
        //_window = glfwCreateWindow(mode->width, mode->height, _title.c_str(), _monitor, NULL);

        ////////////////////////////////

        _window = glfwCreateWindow((int)_width, (int)_height, _title.c_str(), NULL, NULL);
        if (System::Checking(_window == NULL, System::_Fatal, NULL)) {
            this->~Window();
            return;
        }
        Set_Window_Icon(_window, _Icon);
        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, this);
        //glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetWindowSizeLimits(_window, (int)_width, (int)_height, GLFW_DONT_CARE, GLFW_DONT_CARE);
        glfwSetWindowAspectRatio(_window, (int)_width, (int)_height);
        const GLFWvidmode* _mode = glfwGetVideoMode(_monitor);
        iptr xpos = (_mode->width - _width) / 2;
        iptr ypos = (_mode->height - _height) / 2;
        glfwSetWindowPos(_window, (int)xpos, (int)ypos);
        glfwSetWindowOpacity(_window, 0.93f);

        ////////////////////////////////

        //glfwSetCursorPosCallback(_window, Cursor_Pos_Callback);
        //glfwSetFramebufferSizeCallback(_window, Framebuffer_Size_Callback);
        //glfwSetKeyCallback(_window, Key_Callback);
        //glfwSetScrollCallback(_window, Scroll_Callback);
        //glfwSetWindowCloseCallback(_window, Window_Close_Callback);
        //glfwSetWindowContentScaleCallback(_window, Window_Content_Scale_Callback);
        //glfwSetWindowFocusCallback(_window, Window_Focus_Callback);
        //glfwSetWindowIconifyCallback(_window, Window_Iconify_Callback);
        //glfwSetWindowMaximizeCallback(_window, Window_Maximize_Callback);
        //glfwSetWindowPosCallback(_window, Window_Pos_Callback);
        //glfwSetWindowRefreshCallback(_window, Window_Refresh_Callback);
        //glfwSetWindowSizeCallback(_window, Window_Size_Callback);

        ////////////////////////////////

        iptr loader = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (System::Checking(loader == 0, System::_Fatal, NULL)) {
            this->~Window();
            return;
        }
        Window::_Windows.push_back(this);

        ////////////////////////////////

        System::Logging("GL_VENDOR = %s", glGetString(GL_VENDOR));
        System::Logging("GL_RENDERER = %s", glGetString(GL_RENDERER));
        System::Logging("GL_SHADING_LANGUAGE_VERSION = %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
        int attributes = 0;
        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &attributes);
        System::Logging("GL_MAX_VERTEX_ATTRIBS = %td", (iptr)attributes);
    }

    virtual ~Window() {
        System::Logging(__FUNCTION__);

        if (_window != NULL) {
            glfwDestroyWindow(_window);
        }
    }

public:
    static void Set_Window_Icon(GLFWwindow* window, const std::string& filename) {
        System::Logging(__FUNCTION__);

        GLFWimage icons[1];
        int channel = 0;
        stbi_set_flip_vertically_on_load(false);
        icons[0].pixels = stbi_load((Setting::_Images + filename).c_str(), &icons[0].width, &icons[0].height, &channel, 4);  // note: 4 for RGBA.
        glfwSetWindowIcon(window, 1, icons);
    }

    static void Cursor_Pos_Callback(GLFWwindow* window, double xpos, double ypos) {
        System::Logging(__FUNCTION__);

        static Window* user = (Window*)glfwGetWindowUserPointer(window);
        static bool once = true;
        static double xlast = 0.0;
        static double ylast = 0.0;
        if (once == true) {
            once = false;
            xlast = xpos;
            ylast = ypos;
        }
        double xoffset = xpos - xlast;
        double yoffset = ylast - ypos;  // note: [xpos, ypos] in screen coordinate.
        xlast = xpos;
        ylast = ypos;
        // user->_camera.Update_Cursor_Pos((float)xoffset, (float)yoffset, true);
    }

    static void Framebuffer_Size_Callback(GLFWwindow* window, int width, int height) {
        System::Logging(__FUNCTION__);

        static Window* user = (Window*)glfwGetWindowUserPointer(window);
        glViewport(0, 0, width, height);

        // note: the equivalent routine.
        glfwGetFramebufferSize(window, &width, &height);
    }

    static void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        System::Logging(__FUNCTION__);

        Exception::Excepting(true, System::_Warn, "obsolete routine", "use Get_Key() instead.");
        static Window* user = (Window*)glfwGetWindowUserPointer(window);
        //if (GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        //    glfwSetWindowShouldClose(window, true);
        //} else if (key == GLFW_KEY_W) {
        //    user->_camera.Update_Key(Camera::_Forward, 10.0f * (float)user->_delta);
        //} else if (key == GLFW_KEY_S) {
        //    user->_camera.Update_Key(Camera::_Backward, 10.0f * (float)user->_delta);
        //} else if (key == GLFW_KEY_A) {
        //    user->_camera.UpdateKey(Camera::_Leftward, 10.0f * (float)user->_delta);
        //} else if (key == GLFW_KEY_D) {
        //    user->_camera.Update_Key(Camera::_Rightward, 10.0f * (float)user->_delta);
        //} else {
        //    System::Checking(true, System::_Info, "key == ?");
        //}
    }

    static void Scroll_Callback(GLFWwindow* window, double xoffset, double yoffset) {
        System::Logging(__FUNCTION__);

        static Window* user = (Window*)glfwGetWindowUserPointer(window);
        // user->_camera.Update_Scroll((float)xoffset, (float)yoffset);
    }

    static void Window_Close_Callback(GLFWwindow* window) {
        System::Logging(__FUNCTION__);

        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    static void Window_Content_Scale_Callback(GLFWwindow* window, float xscale, float yscale) {
        System::Logging(__FUNCTION__);

        // note: the equivalent routine.
        glfwGetWindowContentScale(window, &xscale, &yscale);
    }

    static void Window_Focus_Callback(GLFWwindow* window, int focused) {
        System::Logging(__FUNCTION__);

        // note: the equivalent routine.
        focused = glfwGetWindowAttrib(window, GLFW_FOCUSED);
    }

    static void Window_Iconify_Callback(GLFWwindow* window, int iconified) {
        System::Logging(__FUNCTION__);

        // note: the equivalent routine.
        //iconified = glfwGetWindowAttrib(window, GLFW_ICONIFIED);

        //glfwIconifyWindow(window);
        //glfwRestoreWindow(window);
        //glfwRequestWindowAttention(window);
    }

    static void Window_Maximize_Callback(GLFWwindow* window, int maximized) {
        System::Logging(__FUNCTION__);

        // note: the equivalent routine.
        //maximized = glfwGetWindowAttrib(window, GLFW_MAXIMIZED);

        //glfwMaximizeWindow(window);
        //glfwRestoreWindow(window);
    }

    static void Window_Pos_Callback(GLFWwindow* window, int xpos, int ypos) {
        System::Logging(__FUNCTION__);

        // note: the equivalent routine.
        //glfwGetWindowPos(window, &xpos, &ypos);
    }

    static void Window_Refresh_Callback(GLFWwindow* window) {
        System::Logging(__FUNCTION__);

        glfwSwapBuffers(window);
    }

    static void Window_Size_Callback(GLFWwindow* window, int width, int height) {
        System::Logging(__FUNCTION__);
        // note: don't pass the window size to glViewport or other pixel-based OpenGL calls.
        // note: the window size is in screen coordinates, not pixels.

        // note: the equivalent routine.
        //glfwGetWindowSize(window, &width, &height);
        //glfwGetWindowFrameSize(window, &left, &top, &right, &bottom);
    }

public:
    virtual void Setup() {
        System::Logging(__FUNCTION__);

        glEnable(GL_DEPTH_TEST);
        //glEnable(GL_CULL_FACE);
        //glFrontFace(GL_CCW);
        //glCullFace(GL_BACK);

        glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(_window);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwShowWindow(_window);
        // int visible = glfwGetWindowAttrib(_window, GLFW_VISIBLE);
        glfwFocusWindow(_window);
    }

    virtual void Render() {
        // System::Logging(__FUNCTION__);

        glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    }

    virtual void Loop() {
        System::Logging(__FUNCTION__);

        Setup();
        while (glfwWindowShouldClose(_window) == false) {
            double current = glfwGetTime();
            _delta = current - _elapsed;
            _elapsed = current;

            Render();
            glfwSwapBuffers(_window);

            Get_Key();
            glfwPollEvents();
        }
        Cleanup();
    }

    virtual void Cleanup() {
        System::Logging(__FUNCTION__);

    }

    virtual void Get_Key() {
        // System::Logging(__FUNCTION__);

        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(_window, true);
        }
        //else if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
        //    _camera.Update_Key(Camera::_Forward, (float)_delta);
        //} else if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
        //    _camera.Update_Key(Camera::_Backward, (float)_delta);
        //} else if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
        //    _camera.Update_Key(Camera::_Leftward, (float)_delta);
        //} else if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
        //    _camera.Update_Key(Camera::_Rightward, (float)_delta);
        //}
    }
};

////////////////////////////////////////////////////////////////////////////////

class Application {
public:
    static inline const iptr _Major = 4;
    static inline const iptr _Minor = 5;

public:
    int _major = 0;
    int _minor = 0;
    int _revision = 0;

public:
    Application() {
        System::Logging(__FUNCTION__);

        glfwSetErrorCallback(Error_Callback);
        glfwInit();
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, _Major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, _Minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);         // note: #ifdef __APPLE__: GL_TRUE

        ////////////////////////////////

        glfwGetVersion(&_major, &_minor, &_revision);
        System::Logging("runtime version: major = %td, minor = %td, revision = %td", (iptr)_major, (iptr)_minor, (iptr)_revision);
        System::Logging("compile version: Major = %td, Minor = %td, Revision = %td", (iptr)GLFW_VERSION_MAJOR, (iptr)GLFW_VERSION_MINOR, (iptr)GLFW_VERSION_REVISION);
        System::Logging("compile version: Version = %s", glfwGetVersionString());

        ////////////////////////////////

        Window* window = new Window();
        window->Loop();
        //for (bool close = false; close == false;) {
        //    close = true;
        //    auto windows = Window::_Windows;
        //    for (iptr i = 0, numb = windows.size(); i < numb; i += 1) {
        //        if ((windows[i] != nullptr) && (glfwWindowShouldClose(windows[i]->_window) == false)) {
        //            close = false;
        //            GLFWwindow* context = glfwGetCurrentContext();
        //            if (context != windows[i]->_window) {
        //                glfwMakeContextCurrent(windows[i]->_window);
        //            }
        //            glClear(GL_COLOR_BUFFER_BIT);
        //            glfwSwapBuffers(windows[i]->_window);
        //        }
        //    }
        //    glfwPollEvents();
        //}
    }

    virtual ~Application() {
        System::Logging(__FUNCTION__);
        glfwTerminate();
    }

public:
    static void Error_Callback(int error_code, const char* description) {
        System::Logging(__FUNCTION__);

        System::Checking(error_code != GLFW_NO_ERROR, System::_Error, "[%td] %s", (iptr)error_code, description);
        // note: the equivalent routine.
        // error_code = glfwGetError(&description);
    }
};

#endif // Application_h
