//
// Created by cx9ps3 on 03.01.23.
//

#ifndef MANDELBROTSCREENSAVER_VERTEXATTRIBUTES_HPP
#define MANDELBROTSCREENSAVER_VERTEXATTRIBUTES_HPP
#include <cstddef>
class VertexAttributes
{
public:
    void add(int size,int stride,int offset);
    void vertexDivisor(int index,int divisor);
private:
    int attributes{0};
};
#endif //MANDELBROTSCREENSAVER_VERTEXATTRIBUTES_HPP
