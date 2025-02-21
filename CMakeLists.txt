cmake_minimum_required(VERSION 3.20) # Ensure CMake version.
project(todo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20) # Use c++20
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Ensure c++20 is required
set(CMAKE_CXXEXTENSIONS OFF) # Use only standart c++

add_executable(todo main.cpp) # Create the executable from main.cpp
