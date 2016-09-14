# PA1: Spinning Cube

## Notes

### Shader files
For the following project there is a shader directory that has two shader files: <br> 
    1) LoadFragShaders.txt <br>
    2) LoadVertexShaders.txt <br>

### Shader Load Function
For loading the shaders I read in the above files and stored the text into a string

### Rotation and Spinning
To spin and rotate the cube the functions in this order will cause the cube to rotate and spin
```bash
model = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));
model = glm::translate ( (model), glm::vec3(5.0, 1.0, 0.0));
```

## Building and Running this example
Running this example requires some libraries to be installed on either Ubuntu or Mac 

### For Ubuntu:
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev
```

### For Mac:
```bash
brew install glew glm sdl2
```

### Running this program
To build this example just
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./Tutorial
```

