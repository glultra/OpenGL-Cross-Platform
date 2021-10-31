include_directories(
    PUBLIC ../include/
    PUBLIC ../external/glad/include/
    PUBLIC ../include/vendor/
)

add_library(Engine Shader.cpp)