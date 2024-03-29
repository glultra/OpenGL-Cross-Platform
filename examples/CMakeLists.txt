cmake_minimum_required(VERSION 3.14.0)

#option(BUILD_ASSIMP "Build assimp library" OFF)

project(window)
project(rectangle)
project(shader)
project(transformation)
project(texture)
project(pyramid)
project(cubes)
project(camera)
project(imgui)
project(material)
project(lightmaps)
project(multiplelights)
project(project)
IF(BUILD_ASSIMP)
    project(model)
ENDIF()
project(tileMap)
project(tileMap2)

add_executable(window window.cpp)
add_executable(rectangle rectangle.cpp)
add_executable(shader shader.cpp)
add_executable(transformation transformation.cpp)
add_executable(texture texture.cpp)
add_executable(pyramid pyramid.cpp)
add_executable(cubes cubes.cpp)
add_executable(camera camera.cpp)
add_executable(imgui imgui.cpp)
add_executable(material material.cpp)
add_executable(lightmaps lightmaps.cpp)
add_executable(multiplelights multiplelights.cpp)
add_executable(project project.cpp)
IF(BUILD_ASSIMP)
    add_executable(model 3D_model.cpp)
ENDIF()
add_executable(tileMap tileMap.cpp)
add_executable(tileMap2 tileMap2.cpp)

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
    target_link_libraries(shader glfw GLAD shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(transformation glfw GLAD Engine shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(texture glfw GLAD Engine STB shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(pyramid glfw GLAD Engine STB shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(cubes glfw GLAD Engine STB shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(camera glfw GLAD Engine STB shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(imgui glfw GLAD Engine STB IMGUI shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(material glfw GLAD Engine STB IMGUI shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(lightmaps glfw GLAD Engine STB IMGUI shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(multiplelights glfw GLAD Engine STB IMGUI shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(project glfw GLAD Engine STB IMGUI shell32 user32 opengl32 winmm gdi32)
    IF(BUILD_ASSIMP)
        target_link_libraries(model glfw GLAD Engine STB IMGUI assimp shell32 user32 opengl32 winmm gdi32)
    ENDIF()
    target_link_libraries(tileMap glfw GLAD Engine STB shell32 user32 opengl32 winmm gdi32)
    target_link_libraries(tileMap2 glfw GLAD Engine STB shell32 user32 opengl32 winmm gdi32)

ELSEIF(UNIX)
    target_link_libraries(window glfw GLAD dl)
    target_link_libraries(rectangle glfw GLAD dl)
    target_link_libraries(shader glfw GLAD dl)
    target_link_libraries(transformation glfw GLAD Engine dl)
    target_link_libraries(texture glfw GLAD Engine STB dl)
    target_link_libraries(pyramid glfw GLAD Engine STB dl)
    target_link_libraries(cubes glfw GLAD Engine STB dl)
    target_link_libraries(camera glfw GLAD Engine STB dl)
    target_link_libraries(imgui glfw GLAD Engine STB IMGUI dl)
    target_link_libraries(material glfw GLAD Engine STB IMGUI dl)
    target_link_libraries(lightmaps glfw GLAD Engine STB IMGUI dl)
    target_link_libraries(multiplelights glfw GLAD Engine STB IMGUI dl)
    target_link_libraries(project glfw GLAD Engine STB IMGUI dl)
    IF(BUILD_ASSIMP)
        target_link_libraries(model glfw GLAD Engine STB IMGUI assimp dl)
    ENDIF()
    target_link_libraries(tileMap glfw GLAD Engine STB dl)
    target_link_libraries(tileMap2 glfw GLAD Engine STB dl)

ELSEIF(APPLE)
    target_link_libraries(window glfw GLAD)
    target_link_libraries(rectangle glfw GLAD)
    target_link_libraries(shader glfw GLAD)
    target_link_libraries(transformation glfw GLAD Engine)
    target_link_libraries(pyramid glfw GLAD Engine STB)
    target_link_libraries(cubes glfw GLAD Engine STB)
    target_link_libraries(camera glfw GLAD Engine STB)
    target_link_libraries(imgui glfw GLAD Engine STB IMGUI)
    target_link_libraries(material glfw GLAD Engine STB IMGUI)
    target_link_libraries(lightmaps glfw GLAD Engine STB IMGUI)
    target_link_libraries(multiplelights glfw GLAD Engine STB IMGUI)
    target_link_libraries(project glfw GLAD Engine STB IMGUI)
    IF(BUILD_ASSIMP)
        target_link_libraries(model glfw GLAD Engine STB IMGUI assimp)
    ENDIF()
    target_link_libraries(tileMap glfw GLAD Engine STB)
    target_link_libraries(tileMap2 glfw GLAD Engine STB)

ENDIF()