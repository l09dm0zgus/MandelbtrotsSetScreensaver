//
// Created by cx9ps3 on 12.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_RECTANGLEDATA_HPP
#define MANDELBROTSCREENSAVER_RECTANGLEDATA_HPP
enum Sizes
{
    VERTICES_ARRAY_SIZE = 12,
    INDICES_ARRAY_SIZE = 6,

};
struct RectangleData
{
    const float vertices[Sizes::VERTICES_ARRAY_SIZE] =
            {
                    -1.0f, -1.0f, -0.0f,
                    1.0f,  1.0f, -0.0f,
                    -1.0f,  1.0f, -0.0f,
                    1.0f, -1.0f, -0.0f
            };
    const unsigned int indices[Sizes::INDICES_ARRAY_SIZE] =
            {
                    0, 1, 2,
                    0, 3, 1
            };
    static constexpr int verticesArraysize = Sizes::VERTICES_ARRAY_SIZE * sizeof(float);
    static constexpr int indicesArraySize = Sizes::INDICES_ARRAY_SIZE * sizeof(unsigned int);
};


#endif //MANDELBROTSCREENSAVER_RECTANGLEDATA_HPP
