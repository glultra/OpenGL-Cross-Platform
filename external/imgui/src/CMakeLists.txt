include_directories(
    PUBLIC ../../glfw/include/
    PUBLIC ../include/
    PUBLIC ../glad/include/
)

add_library(IMGUI imgui.cpp imgui_impl_glfw.cpp imgui_impl_opengl3.cpp imgui_demo.cpp imgui_draw.cpp imgui_tables.cpp imgui_widgets.cpp)