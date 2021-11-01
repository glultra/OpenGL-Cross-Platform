include_directories(
    PUBLIC ../include/
    PUBLIC ../external/glad/include/
    PUBLIC ../include/vendor/
    PUBLIC ../external/assimp/include/
)

add_library(Engine Shader.cpp Model.cpp)