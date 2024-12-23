cmake_minimum_required(VERSION 3.5.0)
project(Task VERSION 0.1.0 LANGUAGES C CXX)


set(SOURCES 
main.cpp
functions.cpp
header.h)
add_executable(Task ${SOURCES})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_CLANG_TIDY  clang-tidy; checks=*;-warnings-as-errors=*;)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
