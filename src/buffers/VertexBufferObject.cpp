//
// Created by cx9ps3 on 02.01.23.
//

#include <iostream>
#include "VertexBufferObject.hpp"
#include "GL/glew.h"


VertexBufferObject::VertexBufferObject()
{
    glGenBuffers(1,&object);
}

VertexBufferObject::~VertexBufferObject()
{
    glDeleteBuffers(1, &object);
}

void VertexBufferObject::bind(const RectangleData &data) const
{
    glBindBuffer(GL_ARRAY_BUFFER,object);
    glBufferData(GL_ARRAY_BUFFER,RectangleData::verticesArraysize,data.vertices,GL_STATIC_DRAW);
}

void VertexBufferObject::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

