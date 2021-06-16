# VEXcodeProject

An example project showcasing building a VEXcode C++ project on a computer.

## Requirements

- CMake (3.6+)
- C++ compiler (g++, Clang, Visual Studio, etc.)

### Optional

- VEXcode Pro V5 (for building for the V5)

## Building

This project uses ```VEXcode Pro V5``` (which is really just ```gcc-arm-none-eabi```) for building for the V5 and ```cmake``` for building for other architectures.

To build for PC:

1. Run ```cmake . -B build``` to generate the build files in ```build/```
2. Build the project

## Running

On Windows, the program will break every time it uses an uninitialized variable (which is quite often). Try using an UNIX-like system instead. The program can be ran and debugged just like any other program since it is a native binary.
