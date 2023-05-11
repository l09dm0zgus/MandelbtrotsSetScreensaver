cmake_minimum_required(VERSION 3.25)
project(MandelbrotScreenSaver)

add_subdirectory(submodules/glfw)
add_subdirectory(submodules/glew-cmake)

set(CMAKE_CXX_STANDARD 17)


add_executable(MandelbrotScreenSaver src/main.cpp src/messages/Messages.hpp)
target_link_libraries(MandelbrotScreenSaver libglew_static glfw)