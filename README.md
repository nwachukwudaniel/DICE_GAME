# C++ Dice Game

A console-based dice game written in C++ using object-oriented programming.

## Overview
The project simulates a dice game between players. It demonstrates how to organize a small C++ application into separate classes and source files.

## Project Structure
- `Dice.hpp` / `Dice.cpp` — Dice behavior and random roll logic
- `Player.hpp` / `Player.cpp` — Player information and score handling
- `Eng_nwachukwu_HA_Client.cpp` — Main program and game flow
- `CMakeLists.txt` — CMake build configuration

## Features
- Dice rolling
- Player score tracking
- Console-based gameplay
- Object-oriented design using classes

## Build and Run

```bash
cmake -S . -B build
cmake --build build
```

Run the generated executable from the `build` directory.

## Topics Demonstrated
- C++ classes and objects
- Header files and implementation files
- Encapsulation
- Random number generation
- CMake
