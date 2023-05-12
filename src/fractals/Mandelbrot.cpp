//
// Created by cx9ps3 on 11.05.2023.
//

#include "Mandelbrot.hpp"
#include "GL/glew.h"

Mandelbrot::Mandelbrot(int windowWidth, int windowHeight, const std::string &vertexShaderPath,const std::string &fragmentShaderPath)
{
    shaderProgram = std::make_unique<ShaderProgram>(vertexShaderPath,fragmentShaderPath);
    VAO.bind();
    VBO.bind(rectangleData);
    EBO.bind(rectangleData);
    attributes.add(3,3,0);
    VBO.unbind();
    VAO.unbind();
    EBO.unbind();
}

void Mandelbrot::draw() noexcept
{

    shaderProgram->setDoubleUniform("width",static_cast<double>(800));
    shaderProgram->setDoubleUniform("height",static_cast<double>(600));
    shaderProgram->setIntegerUniform("maxIterations",250);
    shaderProgram->use();
    VAO.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
