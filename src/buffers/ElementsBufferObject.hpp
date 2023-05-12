//
// Created by cx9ps3 on 12.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_ELEMENTSBUFFEROBJECT_HPP
#define MANDELBROTSCREENSAVER_ELEMENTSBUFFEROBJECT_HPP


#include "RectangleData.hpp"

class ElementsBufferObject
{
public:
    ElementsBufferObject();
    ~ElementsBufferObject();
    void bind(const RectangleData &data) const;
    void unbind();
private:
    unsigned int object{0};
};


#endif //MANDELBROTSCREENSAVER_ELEMENTSBUFFEROBJECT_HPP
