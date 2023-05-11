//
// Created by cx9ps3 on 04.01.23.
//

#include "VertexArrayObject.hpp"
#include "GL/glew.h"

VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1,&object);
}

void VertexArrayObject::bind()
{
    glBindVertexArray(object);

}

VertexArrayObject::~VertexArrayObject()
{
    glDeleteVertexArrays(1, &object);
}

void VertexArrayObject::unbind()
{
    glBindVertexArray(0);
}
