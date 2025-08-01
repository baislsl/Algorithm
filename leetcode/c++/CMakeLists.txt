cmake_minimum_required(VERSION 3.31)
project(leetCode)

set(CMAKE_CXX_STANDARD 17)

include_directories(../../modules)

add_executable(leetCode main.cpp)

add_executable(1 WeeklyContest460/1.cpp)
add_executable(2 WeeklyContest460/2.cpp)
add_executable(3 WeeklyContest460/3.cpp)
add_executable(4 WeeklyContest460/4.cpp)