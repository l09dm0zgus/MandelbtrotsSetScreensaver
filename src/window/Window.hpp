//
// Created by cx9ps3 on 13.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_WINDOW_HPP
#define MANDELBROTSCREENSAVER_WINDOW_HPP
#include <GL/glew.h>
#if defined(WIN32) || defined(WIN64)
#include <Windows.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#define GLFW_NATIVE_INCLUDE_NONE
#include <GLFW/glfw3native.h>
#endif
#include <GLFW/glfw3.h>

class Window
{
public:
    explicit Window(bool isFullscreen = false);
#if defined(WIN32) || defined(WIN64)
    explicit Window(HWND descriptowWindow);
#endif
    int getWidth() const noexcept;
    int getHeight() const noexcept;
    void setFullscreen(bool isFullscreen);
    void swapBuffers();
    void clear();
    bool isShouldClose();
    ~Window();
private:
    void initGLFW();
    void initGLFWWindow();
    void initGLEW();
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void resizeCallback(GLFWwindow* window, int width, int height);
    int width{800}, height{600};
    GLFWwindow *window;
};


#endif //MANDELBROTSCREENSAVER_WINDOW_HPP
