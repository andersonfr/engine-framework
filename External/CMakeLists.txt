cmake_minimum_required(VERSION 3.20)

## project name
project(sfml-engine VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp", "src/*/*.cpp", "src/*/*/*.cpp")
add_library(${PROJECT_NAME} ${SOURCES})
## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)
## In most cases better set in the CMake cache
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio system window REQUIRED)

##set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui/i")
##set(ImGui-SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui-sfml")
##add_subdirectory(External/imgui-sfml)


target_include_directories(${PROJECT_NAME} 
PUBLIC 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
PRIVATE
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        sfml-graphics 
        sfml-audio
        sfml-system
        sfml-window
        ${OPENGL_LIBRARIES}
    PRIVATE
)