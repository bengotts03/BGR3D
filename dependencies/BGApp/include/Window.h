#pragma once

#include <GLFW/glfw3.h>

namespace BGAppCore {
    class Window {
    public:
        Window(unsigned int width, unsigned int height);
        ~Window();

        void Update();

        GLFWwindow* GetNativeWindow() const;

        unsigned int GetWindowWidth() const;
        unsigned int GetWindowHeight() const;
    private:
        GLFWwindow* _window;
        unsigned int _width;
        unsigned int _height;
    };
}