![dimo-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/501ae23f-c7b9-4252-9dd5-b44cfc1a6cfc)
# Conway's Game of Life Simulation

## Overview

This is an interactive implementation of Conway's Game of Life using C++ and Raylib. The Game of Life is a cellular automaton simulation where cells evolve based on simple rules, creating complex and fascinating patterns.

## Features

- Interactive grid where you can manually toggle cell states
- Randomize grid functionality
- Start/stop simulation controls
- Dynamic window resizing
- Game speed control
- Fullscreen mode
- Built-in instructions overlay

## Prerequisites

- C++ Compiler (C++11 or later)
- Raylib library

## Build and Run

### Dependencies
- [Raylib](https://www.raylib.com/) graphics library

### Compilation
Compile using your preferred C++ compiler with Raylib. Example:
```bash
g++ -std=c++11 main.cpp Grid.cpp Controler.cpp -o GameOfLife -lraylib
```

## Controls

### Interaction
- **Left Mouse Click**: Toggle cell state (alive/dead)
- **Enter**: Start simulation
- **Space**: Stop simulation
- **R**: Randomize grid
- **C**: Clear grid
- **S**: Speed up simulation
- **D**: Slow down simulation
- **F**: Toggle fullscreen

### Game Rules
#### Living Cell Rules:
- Dies if 0-1 neighbors (solitude)
- Dies if 4+ neighbors (overpopulation)
- Survives with 2-3 neighbors

#### Empty Cell Rules:
- Becomes alive with exactly 3 neighbors

## Video Walkthrough
![Uploading dimo-ezgif.com-video-to-gif-converter.gif…]()
![Video Demo](C:/Users/002/Downloads/dimo-ezgif.com-video-to-gif-converter.gif)

## Technologies
- Language: C++
- Graphics Library: Raylib
- Paradigm: Cellular Automaton Simulation

## Project Structure
- `main.cpp`: Main game loop and event handling
- `Grid.h/Grid.cpp`: Grid management and cell state logic
- `Controler.h/Controler.cpp`: Game state and grid control

## Customization
You can easily modify:
- Grid size
- Initial game speed
- Cell size
- Window dimensions

## Author
Loay Tarek Mostafa
