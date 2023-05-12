//
// Created by cx9ps3 on 12.05.2023.
//

#include "ElementsBufferObject.hpp"
#include "GL/glew.h"

ElementsBufferObject::ElementsBufferObject()
{
    glGenBuffers(1,&object);
}

ElementsBufferObject::~ElementsBufferObject()
{
    glDeleteBuffers(1, &object);
}

void ElementsBufferObject::bind(const RectangleData &data) const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,object);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,RectangleData::indicesArraySize,data.indices,GL_STATIC_DRAW);

}

void ElementsBufferObject::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
