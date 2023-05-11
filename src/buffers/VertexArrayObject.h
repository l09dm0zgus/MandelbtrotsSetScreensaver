//
// Created by cx9ps3 on 04.01.23.
//

#ifndef MANDELBROTSCREENSAVER_VERTEXARRAYOBJECT_H
#define MANDELBROTSCREENSAVER_VERTEXARRAYOBJECT_H

class VertexArrayObject
{
public:
    VertexArrayObject();
    ~VertexArrayObject();
    void bind();
    void unbind();
private:
    unsigned int object;
};
#endif //MANDELBROTSCREENSAVER_VERTEXARRAYOBJECT_H
