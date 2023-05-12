//
// Created by cx9ps3 on 11.05.2023.
//

#ifndef MANDELBROTSCREENSAVER_MESSAGES_HPP
#define MANDELBROTSCREENSAVER_MESSAGES_HPP
#include <string>
#ifdef __WIN32
#include <windows.h>
#else
#include <iostream>
#endif



inline void showErrorMessage(const char *caption = "ERROR" ,const char* errorMessage = "")
{
#ifdef __WIN32
    MessageBoxA(nullptr,errorMessage, caption ,MB_ICONERROR|MB_TASKMODAL);
#else
    //TODO show error message in GUI on linux/mac
    std::cout << "Error:" << errorMessage << "\n";
#endif
}

inline void showInfoMessage(const char* infoMessage)
{
#ifdef __WIN32
    MessageBoxA(nullptr,infoMessage, "INFO" ,MB_ICONINFORMATION|MB_TASKMODAL);
#else
    //TODO show error message in GUI on linux/mac
    std::cout << "Info:" << infoMessage << "\n";
#endif
}
inline void glfwErrorCallback(int error,const char* description)
{
    showErrorMessage("Error",description);
}
#endif //MANDELBROTSCREENSAVER_MESSAGES_HPP
