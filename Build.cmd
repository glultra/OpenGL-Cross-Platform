cmake -S . -B ./build/ -G "MinGW Makefiles" -D BUILD_ASSIMP=ON

cmake --build ./build/

.\build\OpenGL.exe