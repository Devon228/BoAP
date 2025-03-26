cmake_minimum_required(VERSION 3.5.0)
project(Task_5 VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)

add_executable(Task_5 test.cpp)
target_link_libraries(Task_5 ${GTEST_LIBRARIES})

enable_testing()
add_test(add Task_5)
