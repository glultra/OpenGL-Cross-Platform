cmake_minimum_required(VERSION 3.14.0)

project(OpenGL)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(external/glfw-3.3.5)
add_subdirectory(external/assimp)
add_subdirectory(external/glad/src)
add_subdirectory(external/imgui/src)
add_subdirectory(external/stb/src)
add_subdirectory(src)

add_custom_target(always_rebuild ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res ${CMAKE_BINARY_DIR}/res
)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw-3.3.5/include
    PUBLIC external/assimp/include
    PUBLIC external/glad/include
    PUBLIC external/imgui/include
    PUBLIC external/stb/include
    PUBLIC include
    PUBLIC include/vendor
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw-3.3.5/src
    PRIVATE external/assimp/code
    PRIVATE external/glad/src
    PRIVATE external/imgui/src
    PRIVATE src
)

IF(WIN32)
    target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine assimp shell32 user32 opengl32 winmm gdi32)
ELSEIF(UNIX)
    target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine dl)
ELSEIF(APPLE)
    target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine )
ENDIF()