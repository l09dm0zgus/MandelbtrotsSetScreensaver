cmake_minimum_required(VERSION 3.25)
project(MandelbrotScreenSaver)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glew-cmake)
set(GLEW_INCLUDE submodules/glew-cmake/include)
set(CMAKE_CXX_STANDARD 17)

include_directories(${GLEW_INCLUDE})
if (WIN32)
    add_compile_definitions(WIN32)
endif (WIN32)
if (WIN64)
    add_compile_definitions(WIN32)
endif (WIN64)
add_executable(MandelbrotScreenSaver
        src/main.cpp
        src/messages/Messages.hpp
        src/shaders/ShaderProgram.cpp
        src/shaders/ShaderProgram.hpp
        src/buffers/VertexArrayObject.hpp
        src/buffers/VertexArrayObject.cpp
        src/buffers/VertexAttributes.cpp
        src/buffers/VertexAttributes.hpp
        src/buffers/VertexBufferObject.hpp
        src/buffers/VertexBufferObject.cpp
        src/buffers/VertexAttributes.hpp
        src/fractals/Mandelbrot.cpp
        src/fractals/Mandelbrot.hpp
        src/buffers/ElementsBufferObject.cpp
        src/buffers/ElementsBufferObject.hpp
        src/buffers/RectangleData.hpp
        src/window/Window.cpp
        src/window/Window.hpp
        src/application/Application.cpp
        src/application/Application.hpp)
target_link_libraries(MandelbrotScreenSaver libglew_static glfw)