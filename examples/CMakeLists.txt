cmake_minimum_required(VERSION 3.14.0)

project(window)
project(rectangle)

add_executable(window window.cpp)
add_executable(rectangle rectangle.cpp)

include_directories(
    PUBLIC ../external/glfw-3.3.5/include
    PUBLIC ../external/assimp/include
    PUBLIC ../external/glad/include
    PUBLIC ../external/imgui/include
    PUBLIC ../external/stb/include
    PUBLIC ../include
    PUBLIC ../include/vendor
)

link_directories(
    PRIVATE ../external/glfw-3.3.5/src
    PRIVATE ../external/assimp/code
    PRIVATE ../external/glad/src
    PRIVATE ../external/imgui/src
    PRIVATE ../src
)


IF(WIN32)
    target_link_libraries(window glfw GLAD shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(rectangle glfw GLAD shell32 user32 opengl32 winmm gdi32)
ELSEIF(UNIX)
    target_link_libraries(window glfw GLAD dl)
    target_link_libraries(rectangle glfw GLAD dl)
ELSEIF(APPLE)
    target_link_libraries(window glfw GLAD)
    target_link_libraries(rectangle glfw GLAD)
ENDIF()