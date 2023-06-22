cmake_minimum_required(VERSION 3.7...3.24)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(AlgorithmVisualizer VERSION 2.0
                            DESCRIPTION "Algorithm visualiser with SDL2"
                            LANGUAGES CXX)   

include_directories(src/include)
add_library(VizLib src/visualizer_lib.cpp src/include/visualizer_lib.h)
add_library(VisualVector src/visual_vector.cpp src/include/visual_vector.h)

add_executable(AlgViz src/main.cpp)
set_property(TARGET AlgViz PROPERTY CXX_STANDARD 23)
find_package(SDL2 REQUIRED)
target_link_libraries(VizLib PUBLIC SDL2::SDL2)
target_link_libraries(VisualVector PUBLIC SDL2::SDL2)
target_link_libraries(AlgViz VizLib VisualVector)

