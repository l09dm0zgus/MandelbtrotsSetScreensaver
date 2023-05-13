//
// Created by cx9ps3 on 11.05.2023.
//

#include "Mandelbrot.hpp"
#include "GL/glew.h"
#include <random>
#include <thread>
Mandelbrot::Mandelbrot(int windowWidth, int windowHeight):windowHeight(windowHeight),widowWidth(windowWidth)
{
    constexpr auto vertexShader =
    #include "../shaders/MandelbrotVertex.glsl"
            ;
    constexpr auto fragmentShader =
    #include "../shaders/MandelbrotFragment.glsl"
            ;

    shaderProgram = std::make_unique<ShaderProgram>(vertexShader,fragmentShader);
    VAO.bind();
    VBO.bind(rectangleData);
    EBO.bind(rectangleData);
    attributes.add(3,3,0);
    VBO.unbind();
    VAO.unbind();
    EBO.unbind();
    std::thread generatingThread([this](){generateRandomScalePosition();});
    generatingThread.detach();
}

void Mandelbrot::draw() noexcept
{
    shaderProgram->setDoubleUniform("width",static_cast<double>(widowWidth));
    shaderProgram->setDoubleUniform("height",static_cast<double>(windowHeight));
    shaderProgram->setIntegerUniform("maxIterations",500);
    shaderProgram->setDoubleUniform("scaleFactor",scale);
    shaderProgram->setIntegerUniform("randomX",randomX);
    shaderProgram->setIntegerUniform("randomY",randomY);
    shaderProgram->use();
    VAO.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    scale -= scaleFactor;
    if(scale < minimalScaleLimit)
    {
        scale = startScale;
    }
}

void Mandelbrot::generateRandomScalePosition()
{
     std::random_device rd;
     std::mt19937 mt(rd());
     std::uniform_int_distribution<int> generateX((widowWidth / 2) - xLimit, (widowWidth / 2) + xLimit);
     std::uniform_int_distribution<int> generateY((windowHeight / 2) - yLimit, (windowHeight / 2 ) + yLimit);
    while(isGenerating)
    {
        randomX = generateX(mt);
        randomY = generateY(mt);
        std::this_thread::sleep_for(threadSleepTime);
    }
}

void Mandelbrot::resize(int width, int height)
{
    this->widowWidth = width;
    this->windowHeight = height;
}
