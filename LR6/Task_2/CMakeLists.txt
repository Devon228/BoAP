cmake_minimum_required(VERSION 3.5.0)
project(Task_2 VERSION 0.1.0 LANGUAGES C CXX)



set(SOURCES main1.cpp init.cpp cinLong.cpp cinText.cpp coutText.cpp createWords.cpp findChain.cpp header1.h)
add_executable(Task_2 ${SOURCES})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_CLANG_TIDY  clang-tidy; checks=*;-warnings-as-errors=*;)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")



#target_link_libraries(Task_3 ${GTEST_LIBRARIES})
#enable_testing()
#add_test(add Task_3)