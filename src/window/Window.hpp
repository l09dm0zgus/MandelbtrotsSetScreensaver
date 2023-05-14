//
// Created by cx9ps3 on 13.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_WINDOW_HPP
#define MANDELBROTSCREENSAVER_WINDOW_HPP
#include <GL/glew.h>
#if defined(WIN32) || defined(WIN64)
#include <Windows.h>
#endif
#include <GLFW/glfw3.h>

class Window
{
public:
    explicit Window(bool isFullscreen = false);
#if defined(WIN32) || defined(WIN64)
    explicit Window(bool isFullscreen ,HWND descriptowWindow);
#endif
    int getWidth() const noexcept;
    int getHeight() const noexcept;
    void setFullscreen(bool isFullscreen);
    void swapBuffers();
    void clear();
    bool isShouldClose();
    ~Window();
private:
#if defined(WIN32) || defined(WIN64)
    HGLRC openGLRenderingContext;
    bool isPreviewMode{false};
#endif
    void initGLFW();
    void initGLFWWindow();
    void initGLEW();
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void resizeCallback(GLFWwindow* window, int windowWidth, int windowHeight);
    static void cursorCallback(GLFWwindow* window, double xpos, double ypos);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    int width;
    int height;
    GLFWwindow *window;
    GLFWmonitor *monitor;
    const GLFWvidmode *mode;
};


#endif //MANDELBROTSCREENSAVER_WINDOW_HPP
