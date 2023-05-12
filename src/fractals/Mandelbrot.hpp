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
class Mandelbrot
{
public:
    Mandelbrot(int windowWidth,int windowHeight,const std::string &vertexShaderPath , const std::string &fragmentShaderPath);
    void draw() noexcept;
private:
    RectangleData rectangleData;
    VertexBufferObject VBO;
    VertexAttributes attributes;
    VertexArrayObject VAO;
    ElementsBufferObject EBO;
    std::unique_ptr<ShaderProgram> shaderProgram{nullptr};
};


#endif //MANDELBROTSCREENSAVER_MANDELBROT_HPP
