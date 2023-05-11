cmake_minimum_required(VERSION 3.25)
project(MandelbrotScreenSaver)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glew-cmake)
set(GLEW_INCLUDE submodules/glew-cmake/include)
set(CMAKE_CXX_STANDARD 17)

include_directories(${GLEW_INCLUDE})

add_executable(MandelbrotScreenSaver
        src/main.cpp
        src/messages/Messages.hpp
        src/shaders/ShaderFile.cpp
        src/shaders/ShaderFile.hpp
        src/shaders/ShaderProgram.cpp
        src/shaders/ShaderProgram.hpp
        src/buffers/VertexArrayObject.hpp
        src/buffers/VertexArrayObject.cpp
        src/buffers/VertexAttributes.cpp
        src/buffers/VertexAttributes.hpp
        src/buffers/VertexBufferObject.hpp
        src/buffers/VertexBufferObject.cpp
        src/buffers/VertexAttributes.hpp src/fractals/Mandelbrot.cpp src/fractals/Mandelbrot.hpp)
target_link_libraries(MandelbrotScreenSaver libglew_static glfw)