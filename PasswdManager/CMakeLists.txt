cmake_minimum_required(VERSION 3.10)
project(PasswdManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(PasswdManager src/main.cpp src/PasswdManager.cpp)