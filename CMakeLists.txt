cmake_minimum_required(VERSION 3.14.0)

project(OpenGL)

add_executable(${PROJECT_NAME} main.cpp glad.c)

add_subdirectory(external/glfw-3.3.5)
add_subdirectory(external/glad/src)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw-3.3.5/include
    PUBLIC external/glad/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw-3.3.5/src
    PRIVATE external/glad/src
)

IF(WIN32)
    target_link_libraries(${PROJECT_NAME} glfw GLAD shell32 user32 opengl32 winmm gdi32)
ELSEIF(UNIX)
    target_link_libraries(${PROJECT_NAME} glfw GLAD)
ENDIF()