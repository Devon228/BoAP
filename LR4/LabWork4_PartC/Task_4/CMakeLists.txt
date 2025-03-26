cmake_minimum_required(VERSION 3.5.0)
project(Task_4 VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)

add_executable(Task_4 test.cpp)
target_link_libraries(Task_4 ${GTEST_LIBRARIES})

enable_testing()
add_test(add Task_4)

