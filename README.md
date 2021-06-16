# VEX Robotics V5 Runtime Modification

A library to compile code that depends on the VEX Robotics V5 Runtime (v5rt).
Code that depends on this library includes all code built within VEXcode, VEX Coding Studio, and the PROS kernel.

## Requirements

- CMake (3.6+)
- C++ compiler (g++, Clang, Visual Studio, etc.)

## Building

This project uses ```cmake```. To build, run ```cmake . -B build``` and the files required to build will be generated in the ```build/``` directory.

## Usage

The steps may vary depending on what type of program you're using the library with, but they all mostly follow the same steps:

1. Build the library for the platform you want
2. Copy ```include``` into your project (either in its ```include``` or into a separate directory for the library)
3. Copy the library into your project (called ```v5rtmod.lib``` on Windows, and ```libv5rt.a``` on UNIX-like systems)
4. Configure the build system:
   - Add the include directory for ```v5rtmod``` if it's not already included
   - Set the linker to link to ```v5rtmod```
   - Set any other configurations for the platform you're running (Change the compiler, change the archecticure, etc.)

### VEXcode

It is possible to build and run VEXcode projects on a PC. A separate build configuration has to be make to run it. Visual Studio shows breaks every time an uninitialized variable is used, so avoid using Windows if possible. See the example project [VEXcodeDesktop](VEXcodeDesktop/README.md), to see an example of how to build a VEXcode project for a PC using ```cmake```.

### PROS

[It is possible](https://github.com/purduesigbots/pros/issues/104) to compile the PROS kernel, and therefore any projects built on PROS, but so far has only worked for the platform ```arm-none-eabi```. In order to compile it, workarounds would have to be made with  ```FreeRTOS```.

## Future Work

It would be beneficial if this library not only stubbed, but emulated the V5 Runtime.
This would make it possible to debug programs on a computer without access to a robot, and allow for usage of more advanced tools (such as real debuggers).
It could would allow for manipulation of sensor data, and open up a ton of new possibilities.
I came up with [this concept](https://lucid.app/lucidchart/a6ea1318-7c6e-4b39-b33b-b4fc0f09e1ba/view) for a full-fledged emulator a while ago, but it would take a lot of work to get there.
