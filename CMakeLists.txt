cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(InterestingProblems LANGUAGES CXX)

add_executable(MontyHallProblem "${CMAKE_SOURCE_DIR}/src/MontyHallProblem.cpp")
target_include_directories(MontyHallProblem PUBLIC "include")
