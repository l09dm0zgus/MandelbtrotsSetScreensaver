//
// Created by cx9ps3 on 11.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_SHADERPROGRAM_HPP
#define MANDELBROTSCREENSAVER_SHADERPROGRAM_HPP
#include <string>
class ShaderProgram
{
public:
    ShaderProgram(const char * vertexShaderFile,const char *fragmentShaderPath);
    ~ShaderProgram();
    void use() const noexcept;
    void setDoubleUniform(const std::string &uniformName,double value)  const noexcept;
    void setIntegerUniform(const std::string &uniformName,int value)const noexcept;
private:
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
