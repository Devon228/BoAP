cmake_minimum_required(VERSION 3.5.0)
project(Task_3 VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)

add_executable(Task_3 main.cpp)
target_link_libraries(Task_3 ${GTEST_LIBRARIES})
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

enable_testing()
add_test(add Task_3)

