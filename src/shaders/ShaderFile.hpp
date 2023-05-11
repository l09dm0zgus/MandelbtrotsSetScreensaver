//
// Created by cx9ps3 on 11.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_SHADERFILE_HPP
#define MANDELBROTSCREENSAVER_SHADERFILE_HPP
#include <fstream>
class ShaderFile
{
private:
    std::string shaderText;
public:
    void read( const std::string &path);
    const char *getContent();
};
#endif //MANDELBROTSCREENSAVER_SHADERFILE_HPP
