cmake_minimum_required(VERSION 3.20)
## project name
project(smlf-engine)

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## executable 
add_executable(${PROJECT_NAME} "src/main.cpp")

## In most cases better set in the CMake cache
set(SFML_DIR "${CMAKE_SOURCE_DIR}/External/SFML-2.5.1/lib/cmake/SFML")
set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/External/imgui/i")
set(ImGui-SFML_DIR "${CMAKE_SOURCE_DIR}/External/imgui-sfml")
add_subdirectory(External/imgui-sfml)
##add findimgui.cmake path to module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/External/imgui-sfml/cmake")
## find sfml package
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
#find_package(ImGui-SFML REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC ImGui-SFML sfml-graphics sfml-audio
PRIVATE ImGui-SFML::ImGui-SFML)