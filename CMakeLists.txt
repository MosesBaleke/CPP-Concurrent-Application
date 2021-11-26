cmake_minimum_required(VERSION 3.20)
project(Counterthread)

set(CMAKE_CXX_STANDARD 14)

add_executable(Counterthread main.cpp binary_semaphore.cpp binary_semaphore.h)
