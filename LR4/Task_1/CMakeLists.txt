cmake_minimum_required(VERSION 3.5.0)
project(Task_1 VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)

add_executable(Task_1 main.cpp)
target_link_libraries(Task_1 ${GTEST_LIBRARIES})

enable_testing()
add_test(add Task_1)
