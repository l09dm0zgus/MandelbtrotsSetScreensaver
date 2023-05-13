//
// Created by cx9ps3 on 11.05.2023.
//

#include "ShaderProgram.hpp"
#include "../messages/Messages.hpp"
#include <GL/glew.h>

ShaderProgram::ShaderProgram(const char *vertexShaderText,const char *fragmentShaderText): fragmentShaderText(const_cast<char *>(fragmentShaderText)), vertexShaderText(const_cast<char *>(vertexShaderText))
{
    compileVertexShader();
    compileFragmentShader();
    linkShaders();
}

void ShaderProgram::compileVertexShader()
{
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1,&vertexShaderText, nullptr);
    glCompileShader(vertexShader);
    showCompilerLog(vertexShader);
}

inline void ShaderProgram::showCompilerLog(unsigned int shader) const noexcept
{
    int success{0};
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        showErrorMessage("Error:Failed compile shader.",infoLog);
    }
}

inline void ShaderProgram::compileFragmentShader()
{
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1,&fragmentShaderText, nullptr);
    glCompileShader(fragmentShader);
    showCompilerLog(fragmentShader);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void ShaderProgram::linkShaders()
{
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    showLinkerLog();
}

void ShaderProgram::showLinkerLog() const noexcept
{
    int success{0};
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        showErrorMessage("Error:Failed to link shader.",infoLog);
    }
}

void ShaderProgram::use() const noexcept
{
    glUseProgram(shaderProgram);
}


void ShaderProgram::setDoubleUniform(const std::string &uniformName, double value) const noexcept
{
    glUniform1d(glGetUniformLocation(shaderProgram,uniformName.c_str()),value);
}

void ShaderProgram::setIntegerUniform(const std::string &uniformName, int value) const noexcept
{
    glUniform1i(glGetUniformLocation(shaderProgram,uniformName.c_str()),value);
}


