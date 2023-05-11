//
// Created by cx9ps3 on 11.05.2023.
//

#include "ShaderFile.hpp"
#include "../messages/Messages.hpp"
void ShaderFile::read(const std::string &path)
{
    std::fstream file;
    file.exceptions(std::fstream::badbit|std::fstream::failbit);
    try
    {
        file.open(path,std::ios::in);
    }
    catch (const std::fstream::failure &exception)
    {
        showErrorMessage("ERROR",exception.what());
    }
    shaderText.append((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
}

const char *ShaderFile::getContent()
{
    return shaderText.c_str();
}
