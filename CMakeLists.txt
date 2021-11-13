cmake_minimum_required(VERSION 3.14.0)

project(OpenGL)

option(BUILD_ASSIMP "Build assimp library" OFF)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(external/glfw-3.3.5)
IF(BUILD_ASSIMP)
    add_subdirectory(external/assimp)
ENDIF()
add_subdirectory(external/glad/src)
add_subdirectory(external/imgui/src)
add_subdirectory(external/stb/src)
add_subdirectory(src)
add_subdirectory(examples)

add_custom_target(always_rebuild ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res ${CMAKE_BINARY_DIR}/res
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/examples/res ${CMAKE_BINARY_DIR}/examples/res
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
    target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine shell32 user32 opengl32 winmm gdi32)
    IF(BUILD_ASSIMP)
        target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine assimp shell32 user32 opengl32 winmm gdi32)
    ENDIF()
ELSEIF(UNIX)
    target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine dl)
    IF(BUILD_ASSIMP)
        target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine assimp dl)
    ENDIF()
ELSEIF(APPLE)
    target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine)
    IF(BUILD_ASSIMP)
        target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
        target_link_libraries(${PROJECT_NAME} "-framework GLUT")
        target_link_libraries(${PROJECT_NAME} glfw GLAD IMGUI STB Engine assimp)
    ENDIF()
ENDIF()