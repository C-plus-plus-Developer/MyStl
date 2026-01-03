cmake_minimum_required(VERSION 3.10)
project(NewProgramm)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NewProgramm 
        main.cpp
        String.cpp
        LeetCodeTask.cpp
)
