//
// Created by cx9ps3 on 02.01.23.
//

#include "VertexBufferObject.h"
#include "GL/glew.h"


VertexBufferObject::VertexBufferObject()
{
    glGenBuffers(1,&object);
}

VertexBufferObject::~VertexBufferObject()
{
    glDeleteBuffers(1, &object);
}

void VertexBufferObject::bind(const std::vector<int> &vertices)
{
    glBindBuffer(GL_ARRAY_BUFFER,object);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices.data()),vertices.data(),GL_STATIC_DRAW);
}

void VertexBufferObject::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

