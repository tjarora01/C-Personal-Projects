cmake_minimum_required(VERSION 3.12)
project(DivideOperator)

set(CMAKE_CXX_STANDARD 14)

add_executable(DivideOperator main.cpp DivideOperator.cpp DivideEqualsOperator.cpp DivideEqualsOperator.h real.cpp real.h)