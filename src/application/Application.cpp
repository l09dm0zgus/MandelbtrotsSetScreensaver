//
// Created by cx9ps3 on 13.05.2023.
//

#include "Application.hpp"

Application::Application(int argc, char **argv)
{
    window = std::make_unique<Window>();
    mandelbrot = std::make_unique<Mandelbrot>(window->getWidth(),window->getHeight());
}

void Application::run()
{
    while (!window->isShouldClose())
    {
        window->clear();
        mandelbrot->draw();
        window->swapBuffers();
    }
}
