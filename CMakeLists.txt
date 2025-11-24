cmake_minimum_required(VERSION 3.14)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_library(figures
    point.hpp point.ipp
    figure.hpp figure.ipp  
    rectangle.hpp rectangle.ipp
    square.hpp square.ipp
    trapezoid.hpp trapezoid.ipp
    array.hpp array.ipp
)

add_executable(main_app main.cpp)
target_link_libraries(main_app figures)

add_executable(tests tests.cpp) 
target_link_libraries(tests figures GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
