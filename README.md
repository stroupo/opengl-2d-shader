# OpenGL 2D Shader
Simple Test Application to Demonstrate 2D GPGPU-based Rendering

## Requirements
- C++ Standard: C++17
- C++ Compiler: GCC | Clang | Nuwen MinGW | MinGW | MSVC
- Operating System: Linux | Windows
- Build System: [build2](https://build2.org) >= 0.13.0
- Libraries:
    + [glbinding](https://glbinding.org/) ^ 3.1.0
    + [GLFW](https://www.glfw.org/) ^ 3.3.4
    + [GLM](https://glm.g-truc.net/0.9.9/index.html) ^ 0.9.9

## Build and Run with build2
### Linux
Make sure all dependencies are installed.
Clone the project from GitHub and change directory into the project root.

    git clone https://github.com/stroupo/opengl-2d-shader.git
    cd opengl-2d-shader

Initialize a build2 configuration with `bdep` and appropriate compile variables to specify compiler, optimization options, and other include or linker directories.

    bdep init -C @gcc cc config.cxx=g++ config.cxx.coptions="-O3 -march=native"

Build and run the executable by using the build system.

    b test

### Windows
Make sure to read and understand the build and test instructions for Linux.

#### Nuwen MinGW Compiler Distribution
On Windows, I recommend to use the [Nuwen MinGW compiler distribution](https://nuwen.net/mingw.html) because in this distribution of MinGW all needed dependencies are already installed.
Use a custom configuration to be able to find the static libraries.
We want to use the static version of the GLFW library.
Hence, we have to additionally link the library `gdi32` into the application.

    bdep init -C @mingw cc \
        config.cxx=g++ \
        "config.cxx.poptions=-IC:/MinGW/include" \
        "config.cxx.coptions=-O3 -march=native" \
        "config.cxx.loptions=-LC:/MinGW/lib" \
        "config.cxx.libs=-lgdi32"
    b test

#### Microsoft C++ Compiler or MinGW
Using the Microsoft C++ compiler or the standard MinGW compiler distribution, we will probably use dynamic libraries.
So make sure to install all dependencies to appropriate locations and get their include and library paths.
Of course, we have to customize this configuration as well.
Call the following command inside the developer prompt of the MSVC.

    bdep init -C @msvc cc \
        config.cxx=cl \
        "config.cxx.poptions=/IC:/GLFW/include /IC:/glbinding/include /IC:/glm" \
        "config.cxx.coptions=/O2" \
        "config.cxx.loptions=/LIBPATH:C:/GLFW/lib /LIBPATH:C:/glbinding/lib"
    b test

## Usage
- Escape: Quit the program.
