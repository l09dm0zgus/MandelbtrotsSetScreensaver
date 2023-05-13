//
// Created by cx9ps3 on 13.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_APPLICATION_HPP
#define MANDELBROTSCREENSAVER_APPLICATION_HPP
#include "../window/Window.hpp"
#include "../fractals/Mandelbrot.hpp"

class Application
{
private:
    std::unique_ptr<Window> window{nullptr};
    std::unique_ptr<Mandelbrot> mandelbrot{nullptr};
#if defined(WIN32) || defined(WIN64)
    void parseArguments(int argc, char *argv[]);
#endif
public:
    explicit Application(int argc, char *argv[]);
    void run();

};


#endif //MANDELBROTSCREENSAVER_APPLICATION_HPP
