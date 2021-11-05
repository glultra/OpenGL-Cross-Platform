sudo apt-get update;
sudo apt install gcc;
sudo apt install cmake;
sudo apt-get install libx11-dev;
sudo apt-get install -y libxrandr-dev;
sudo apt-get install libxinerama-dev;
sudo apt-get install libxcursor-dev;
sudo apt-get install libxi-dev;
sudo apt-get update;
sudo apt-get install libglfw3 libglfw3-dev;
git clone https://github.com/glULTRA/OpenGL-Cross-Platform.git;
cd OpenGL-Cross-Platform/;
cmake -S . -B ./build/ -G "Unix Makefiles" -D GLFW_BUILD_DOCS=OFF;
cd ./build/;
cmake --build .;
./OpenGL;