//
// Created by cx9ps3 on 11.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_MANDELBROT_HPP
#define MANDELBROTSCREENSAVER_MANDELBROT_HPP
#include "../buffers/VertexArrayObject.hpp"
#include "../buffers/VertexAttributes.hpp"
#include "../buffers/VertexBufferObject.hpp"
#include "../shaders/ShaderProgram.hpp"
#include "../buffers/ElementsBufferObject.hpp"

#include <memory>
#include <chrono>
using namespace std::chrono_literals;

class Mandelbrot
{
public:
    Mandelbrot(int windowWidth,int windowHeight,const std::string &vertexShaderPath , const std::string &fragmentShaderPath);
    void draw() noexcept;
private:
    void generateRandomScalePosition();
    double startScale = 1.0;
    double scale = startScale;
    double scaleFactor = 0.0001;
    double minimalScaleLimit = 0.000001;
    RectangleData rectangleData;
    VertexBufferObject VBO;
    VertexAttributes attributes;
    VertexArrayObject VAO;
    ElementsBufferObject EBO;
    std::unique_ptr<ShaderProgram> shaderProgram{nullptr};
    std::chrono::seconds threadSleepTime = 120s;
    int xLimit = 100;
    int yLimit = 100;
    std::atomic<int> randomX;
    std::atomic<int> randomY;
    std::atomic<bool> isGenerating{true};
    int widowWidth;
    int windowHeight;
};


#endif //MANDELBROTSCREENSAVER_MANDELBROT_HPP
