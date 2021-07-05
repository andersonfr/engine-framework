cmake_minimum_required(VERSION 3.20)
## project name
project(App-Test VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
file(GLOB SOURCES "src/*.cpp", "src/*/*.cpp", "src/*/*/*.cpp")
#add_library(${PROJECT_NAME} ${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-engine)
target_include_directories(${PROJECT_NAME} PRIVATE sfml-engine)