//
// Created by cx9ps3 on 13.05.2023.
//

#include "Application.hpp"
#include "../messages/Messages.hpp"
#include <string>

Application::Application(int argc, char **argv)
{
#if defined(WIN32) || defined(WIN64)
    parseArguments(argc,argv);
#else
    window = std::make_unique<Window>();
    mandelbrot = std::make_unique<Mandelbrot>(window->getWidth(),window->getHeight());
#endif
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
#if defined(WIN32) || defined(WIN64)
void Application::parseArguments(int argc, char *argv[])
{
    if(argc > 2)
    {
        if((strcmp(argv[1],"\\c")  && strcmp(argv[1],"\\C") && strcmp(argv[1],"/c") && strcmp(argv[1],"/C")) == 0)
        {
            showInfoMessage("Created by cx9ps3 :)\n /c - to show this box\n /s - start screen saver in fullscreen\n");
        }
        else if((strcmp(argv[1],"\\s")  && strcmp(argv[1],"\\S") && strcmp(argv[1],"/S") && strcmp(argv[1],"/s")) == 0)
        {
            window = std::make_unique<Window>(true);
        }
        else if((strcmp(argv[1],"\\p")  && strcmp(argv[1],"\\P") && strcmp(argv[1],"/p") && strcmp(argv[1],"/P")) == 0 )
        {
            HWND hwnd= (HWND)std::stol(argv[2]);
            window = std::make_unique<Window>(false,hwnd);
        }
    }
    else
    {
        window = std::make_unique<Window>(false);
        mandelbrot = std::make_unique<Mandelbrot>(window->getWidth(),window->getHeight());
    }
}
#endif