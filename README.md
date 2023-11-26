# Backroom

[Visit Website](https://thingspool.net)

## About this project

This is a custom pseudo-assembly language interpreter I made up from scratch, which runs inside C++.

The "sourceCode.txt" file contains a script written in a pseudo-assembly language. I call it "pseudo" because it is a scripting language which resembles Assembly in some measure (e.g. explicit memory access, etc), but only to a limited extent.

The application translates the script into its corresponding bytecode, and subsequently stores it inside the "byteCode.txt" file.

It then executes the instructions in "byteCode.txt" line by line, treating each of them as an operator followed by operands.

The "Interpreters.cpp" file lists all types of instructions you can use inside your script. If you want an additional functionality, all you need to do is simply implement a new procedure and put its name and function pointer in "interpreterNames" and "interpreters", respectively. Don't forget to make sure that they belong to the same array index.

(NOTE: Colored log outputs in "LogUtil.cpp" may not work on Windows. Its text-based color codes are meant to behave correctly only on Linux and MacOS.)

## How to compile and run

Inside your console window, navigate to the project's root directory and run the following commands:

1. **./configure.sh** (To configure the CMake build settings)
2. **./buildAndRun.sh** (To build and run the project)

If you want to build and run through separate commands, simply use:

- **./build.sh** (To build the project)
- **./run.sh** (To run the project)