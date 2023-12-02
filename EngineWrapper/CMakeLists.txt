cmake_minimum_required(VERSION 3.26)
project(EngineWrapper)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(PROJECT_HEADERS Engine.hpp, Subject.hpp, Wrapper.hpp)
add_executable(Calculator ${PROJECT_SOURCE_DIR}/ main.cpp)