//
// Created by cx9ps3 on 13.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_WINDOW_HPP
#define MANDELBROTSCREENSAVER_WINDOW_HPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    explicit Window(bool isFullscreen = false);
    int getWidth() const noexcept;
    int getHeight() const noexcept;
    void setFullscreen(bool isFullscreen);
    void swapBuffers();
    void clear();
    bool isShouldClose();
    ~Window();
private:
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void resizeCallback(GLFWwindow* window, int width, int height);
    int width{0}, height{0};
    GLFWwindow *window;
};


#endif //MANDELBROTSCREENSAVER_WINDOW_HPP
