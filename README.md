# Setup on Linux 
### You should already have this things

1- `sudo install gcc`
2- `sudo install cmake`

### First download glfw-x11 
$`sudo apt-get install libglfw3 libglfw3-dev`
### Download github repo or clone it
### Open Terminal in the project
### Then type 
`cmake -S . -B ./build/ -G "Unix Makefiles" -D GLFW_BUILD_DOCS=OFF`
### Then goto the built dir
`cd ./build/`
### Then type
`make` or `cmake --build .`
### Wait until every thing is done
`./OpenGL`
