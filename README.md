# Mandelbrot Set screensaver
## Building :
```shell
git clone --recursive https://github.com/l09dm0zgus/MandelbtrotsSetScreensaver.git
cd MandelbtrotsSetScreensaver && mkdir build && cd bild
cmake ..
```
## Installing on Windows:
Right mouse button click on .scr file and choose in menu - Install.
## Screenshot:
![Screenshot](images/img.png)
## TO DO:
+ Add Linux support.
+ Add Vulkan backend for rendering.
+ Remove glfw and glew libraries and use WinApi,XLib,WGL and GLX.
+ Fix not working preview mode on linux.
+ Add screensaver settings window(colors,iterations,etc)