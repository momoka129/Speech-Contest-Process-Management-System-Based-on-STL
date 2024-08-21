cmake_minimum_required(VERSION 3.28)
project(Speech_Contest_Process_Management_System_Based_on_STL)

set(CMAKE_CXX_STANDARD 17)

add_executable(Speech_Contest_Process_Management_System_Based_on_STL main.cpp
        speechManager.cpp
        speechManager.h
        speaker.h
)
