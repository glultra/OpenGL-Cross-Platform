cmake -S . -B ./build/ -G "MinGW Makefiles" -D BUILD_ASSIMP=OFF

cmake --build ./build/

.\build\OpenGL.exe