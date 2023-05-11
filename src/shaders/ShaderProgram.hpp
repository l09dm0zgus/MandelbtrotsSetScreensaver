//
// Created by cx9ps3 on 11.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_SHADERPROGRAM_HPP
#define MANDELBROTSCREENSAVER_SHADERPROGRAM_HPP
#include "ShaderFile.hpp"

class ShaderProgram
{
public:
    ShaderProgram(const std::string &vertexShaderPath,const std::string &fragmentShaderPath);
    ~ShaderProgram();
    void use() const noexcept;
    void setIntUniform(const std::string &uniformVariable,int value) const;
private:
    ShaderFile vertexShaderFile;
    ShaderFile fragmentShaderFile;
    unsigned int vertexShader{0};
    unsigned int fragmentShader{0};
    unsigned int shaderProgram{0};
    char* fragmentShaderText{nullptr};
    char* vertexShaderText{nullptr};

    void compileVertexShader();
    void compileFragmentShader();
    void linkShaders();
    void showCompilerLog(unsigned int shader) const noexcept;
    void showLinkerLog() const noexcept;
};


#endif //MANDELBROTSCREENSAVER_SHADERPROGRAM_HPP
