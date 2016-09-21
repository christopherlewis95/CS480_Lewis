# PA3: Spinning Cube (and Moon) with keyboard interaction Version 3.0

## Notes

### Shader files
For the following project there is a shader directory that has two shader files: <br> 
    1) LoadFragShaders.txt <br>
    2) LoadVertexShaders.txt <br>

### Shader Load Function
For loading the shaders I read in the above files and stored the text into a string

### Rotation and Spinning
To spin and rotate the cube and moon in different ways use the following keys:
```bash
Q - Not functional (Will work in a later update)
W - Not functional (Will work in a later update)
A - Stops rotating the cube and orbits the cube LEFT
S - Stops rotating the cube and orbits the cube RIGHT
Z - Spins the cube left (Rotation & Orbit)
X - Spins the cube right (Rotation & Orbit)
SPACEBAR - Pauses the animation (To unpause.. press A,S,Z, or X)

NEW FEATURE(S) BELOW!
Left Click - Pauses the animation (To unpause.. press A,S,Z, or X)
```

## Plans in version 4.0 (Coming SOON!)
```bash
1) Adding Q & W key interaction
2) Adding a model loader!
```

## Building and Running this example
Running this example requires some libraries to be installed on either Ubuntu or Mac <br>

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

### ERRORS?
<b>IF FOR SOME CHANCE UPON RUNNING THE WINDOW IS BLANK, RUN THESE LINES IN BUILD DIRECTORY..</b>
```bash
$ make clean
$ make 
$ ./Tutorial
```




