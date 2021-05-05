cmake_minimum_required(VERSION 3.20)
## project name
project(smlf-engine)

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## executable 
add_executable(${PROJECT_NAME} "src/main.cpp")

## In most cases better set in the CMake cache
set(SFML_DIR "${CMAKE_SOURCE_DIR}/External/SFML-2.5.1/lib/cmake/SFML")

## find sfml package
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)