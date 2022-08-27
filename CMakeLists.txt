cmake_minimum_required(VERSION 3.7...3.24)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(AlgorithmVisualizer VERSION 1.0
                            DESCRIPTION "Algorithm visualiser with SDL2"
                            LANGUAGES CXX)   

add_library(VizLib src/visualizer_lib.cpp src/visualizer_lib.h)
add_library(BeepLib src/beep.cpp src/beep.h)
add_executable(AlgViz src/main.cpp)
set_property(TARGET AlgViz PROPERTY CXX_STANDARD 20)
find_package(SDL2 REQUIRED)
target_link_libraries(VizLib PUBLIC SDL2::SDL2)
target_link_libraries(BeepLib PUBLIC SDL2::SDL2)
target_link_libraries(AlgViz VizLib BeepLib)

