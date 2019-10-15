cmake_minimum_required(VERSION 3.12)
project(Practice)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp PQueue.h PQueue.cpp)

add_executable(Practice ${SOURCE_FILES})