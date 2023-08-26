# LineEndingDetectionProject

## Project Overview

This project creates a C++ program designed to analyze source code files and detect incorrect line endings (CRLF, LF, CR). The program helps identify lines with incorrect endings and provides information about the type of line endings in each file.

## Features

- Check and report line endings of C++ source files (`*.cpp` and `*.h`) in a specific directory.
- Identify and highlight lines with non-CRLF line endings.
- Summarize whether all lines in each file have consistent line endings.

## Usage

1. Ensure you have a C++ compiler version of at least 9.0 or use another compiler version that supports C++17 and the `<filesystem>` library.
2. Compile the program using CMake and Make.
3. Run the program: `./CRLF`.
4. Enter the path to the directory you want to analyze.
5. The program will search for `.cpp` and `.h` files in the directory and its subdirectories.
6. It will analyze line endings, identify and highlight lines with non-CRLF line endings, and summarize the consistency of line endings.
7. View the results and press Enter to exit.

## Requirements

- `cmake` >= 3.10
- `make` >= 4.1 (Linux/Mac), 3.81 (Windows)
- C++ compiler with C++17 support and the `<filesystem>` library.

## Compiling and Running

`Linux`
To compile the project on Linux, follow these steps:

1.Open a terminal.
2.Navigate to the project directory.
3.Create a build directory and navigate to it:
    mkdir build && cd build
4.Within the build directory, run the following command to generate the build files:
    cmake ..
5.Compile the project using make:
    make
6. Run the compiled program:
    ./CRLF


`Windows (using MinGW)`
To compile the project on Windows using MinGW, follow these steps:

1.Open Command Prompt or PowerShell.
2.Navigate to the project directory.

3.Create a build directory and navigate to it:
    mkdir build
    cd build
4.Within the build directory, use CMake to generate the build files with the "Unix Makefiles" generator:
    cmake -G "Unix Makefiles" ..
5.Use the mingw32-make tool to compile the project:
    mingw32-make
6. Run the compiled program:
    ./CRLF.exe

By following these instructions, you can successfully compile and run the project on both Linux and Windows (using MinGW) operating systems.

## Sample Output

![Sample Output](./DetectTheLineEnding/sample_output.png)
