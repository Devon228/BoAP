cmake_minimum_required(VERSION 3.5.0)
project(Task_2 VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)

add_executable(Task_2 main.cpp)
target_link_libraries(Task_2 ${GTEST_LIBRARIES})

enable_testing()
add_test(add Task_2)