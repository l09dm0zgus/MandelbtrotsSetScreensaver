//
// Created by cx9ps3 on 02.01.23.
//

#ifndef MANDELBROTSCREENSAVER_VERTEXBUFFEROBJECT_H
#define MANDELBROTSCREENSAVER_VERTEXBUFFEROBJECT_H
#include <vector>

class VertexBufferObject
{
public:
    VertexBufferObject();
    ~VertexBufferObject();
    void bind(const std::vector<int> &vertices);
    void unbind();
private:
    unsigned int object{0};
};

#endif //MANDELBROTSCREENSAVER_VERTEXBUFFEROBJECT_H
