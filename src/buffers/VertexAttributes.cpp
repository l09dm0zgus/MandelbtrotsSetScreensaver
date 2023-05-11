//
// Created by cx9ps3 on 03.01.23.
//

#include "VertexAttributes.h"
#include "GL/glew.h"

void VertexAttributes::add(int size,int stride,int offset)
{
    glVertexAttribPointer(attributes, size, GL_FLOAT, GL_FALSE, stride * sizeof(int), (void*)(offset * sizeof(int)));
    glEnableVertexAttribArray(attributes);
    attributes++;
}

void VertexAttributes::vertexDivisor(int index, int divisor)
{
    glVertexAttribDivisor(index,divisor);
}
