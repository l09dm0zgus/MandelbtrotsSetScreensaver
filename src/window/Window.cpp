//
// Created by cx9ps3 on 13.05.2023.
//

#include "Window.hpp"
#include "../messages/Messages.hpp"

Window::Window(bool isFullscreen)
{

    initGLFW();
    initGLFWWindow();
    initGLEW();
    //setFullscreen(isFullscreen);
}
#if defined(WIN32) || defined(WIN64)
Window::Window(HWND descriptor)
{   initGLFW();
    initGLFWWindow();
    window = glfwAttachWin32Window(descriptor, window);
    initGLEW();
}
#endif
Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void Window::swapBuffers()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::clear()
{
    glClearColor(0.39f, 0.58f, 0.93f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Window::isShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::resizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0,0, width,height);
    glfwGetWindowSize(window, &width, &height);
}

int Window::getWidth() const noexcept
{
    return width;
}

int Window::getHeight() const noexcept
{
    return height;
}

void Window::setFullscreen(bool isFullscreen)
{
    auto monitor = glfwGetWindowMonitor(window);
    auto mode = glfwGetVideoMode(monitor);
    if(isFullscreen)
    {
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        glViewport(0,0,mode->width,mode->height);
    }
    else
    {
        glfwSetWindowMonitor(window, nullptr,0,0,width,height,0);
        glViewport(0,0,width,height);

    }
}

void Window::initGLFW()
{
    if(!glfwInit())
    {
        showErrorMessage("ERROR","Failed to initialize GLFW\n");
        exit(-1);
    }
    glfwSetErrorCallback(glfwErrorCallback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_ANY_PROFILE);
}

void Window::initGLFWWindow()
{
    window = glfwCreateWindow(width,height,"Mandelbrot Screensaver", nullptr, nullptr);
    if(window == nullptr)
    {
        showErrorMessage("ERROR","Failed to open main screen");
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window,Window::keyCallback);

}

void Window::initGLEW()
{
    if(glewInit() != GLEW_OK)
    {
        showErrorMessage("ERROR","Failed to initialize GLEW\n");
        exit(-1);
    }
}