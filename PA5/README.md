# PA4: Model Loading

## Notes
For this project I was tasked with creating a model loader and then loading a .OBJ file in Blender for export so that it can be loaded in the program. 


## OBJ File
The following code for my .OBJ file is contained under PA4/objects/boxR.obj
```bash
# Blender v2.77 (sub 0) OBJ File: 'boxR.blend'
# www.blender.org
mtllib boxR.mtl
o Cube
v 1.531411 0.409797 -2.291103
v 1.531411 0.409797 2.291103
v -1.531411 0.409797 2.291102
v -1.531410 0.409797 -2.291104
v 1.531412 -0.409797 -2.291102
v 1.531410 -0.409797 2.291104
v -1.531412 -0.409797 2.291102
v -1.531411 -0.409797 -2.291103
vn 0.0000 -1.0000 0.0000
vn 0.0000 1.0000 0.0000
vn -1.0000 -0.0000 0.0000
vn 0.0000 -0.0000 -1.0000
vn 1.0000 -0.0000 0.0000
vn -0.0000 0.0000 1.0000
usemtl Material
s off
f 2//1 4//1 1//1
f 5//2 7//2 6//2
f 5//3 2//3 1//3
f 6//4 3//4 2//4
f 3//5 8//5 4//5
f 1//6 8//6 5//6
f 2//1 3//1 4//1
f 5//2 8//2 7//2
f 5//3 6//3 2//3
f 6//4 7//4 3//4
f 3//5 7//5 8//5
f 1//6 4//6 8//6
```

## Secondary OBJ
My secondary .OBJ file is contained under PA4/objects/box_open.obj
```bash
# Blender v2.77 (sub 0) OBJ File: ''
# www.blender.org
o Cube
v 1.000000 -1.000000 -1.000000
v 1.000000 -1.000000 1.000000
v -1.000000 -1.000000 1.000000
v -1.000000 -1.000000 -1.000000
v 1.000000 1.000000 -0.999999
v 0.999999 1.000000 1.000001
v -1.000000 1.000000 1.000000
v -1.000000 1.000000 -1.000000
v 0.849000 -0.849000 -0.849000
v -0.849000 -0.849000 -0.849000
v -0.849000 -0.849000 0.849000
v 0.849000 -0.849000 0.849000
v 0.848999 1.000000 0.849001
v 0.849000 1.000000 -0.849000
v -0.849000 1.000000 0.849000
v -0.849000 1.000000 -0.849000
vn 0.0000 -1.0000 0.0000
vn 1.0000 -0.0000 0.0000
vn 0.0000 -0.0000 1.0000
vn -1.0000 -0.0000 -0.0000
vn 0.0000 0.0000 -1.0000
vn 0.0000 1.0000 -0.0000
s off
f 2//1 4//1 1//1
f 5//2 2//2 1//2
f 6//3 3//3 2//3
f 3//4 8//4 4//4
f 1//5 8//5 5//5
f 10//6 12//6 9//6
f 12//4 14//4 9//4
f 11//5 13//5 12//5
f 10//2 15//2 11//2
f 16//3 9//3 14//3
f 8//6 14//6 5//6
f 6//6 15//6 7//6
f 5//6 13//6 6//6
f 7//6 16//6 8//6
f 2//1 3//1 4//1
f 5//2 6//2 2//2
f 6//3 7//3 3//3
f 3//4 7//4 8//4
f 1//5 4//5 8//5
f 10//6 11//6 12//6
f 12//4 13//4 14//4
f 11//5 15//5 13//5
f 10//2 16//2 15//2
f 16//3 10//3 9//3
f 8//6 16//6 14//6
f 6//6 13//6 15//6
f 5//6 14//6 13//6
f 7//6 15//6 16//6

```

### Model Loading function
To load the above two files I made a loader that parses the information the function below in the Object constructor
```bash
getObj();
```

### Implementation of the Model Loading function
Below is the implementation of the Model Loader
```bash
void Object::getObj()
{
  std::string s, string1, string2, string3;
  std::string readline;
  std::ifstream fin;
  float val1, val2, val3;

  // Open the file from the outside directory (Will change to input later)
  fin.open( "../objects/boxR.obj" );

  getline(fin, readline);
  while(readline[0]!= 'o')
  {
  getline(fin, readline);
  }

  // While the file is "GOOD" read the file and concatinate it to the string
  while(fin.good())
      {
        // Make new vertex
        fin >> s;
       // cout << "The char is:" << s << endl;
        if( s == "v")
        {
          fin >> val1 >> val2 >> val3;
          Vertex *vert = new Vertex(glm::vec3(val1,val2,val3),glm::vec3(1.0f,0.0f,0.0f));

          Vertices.push_back(*vert);
        }
        if( s == "f")
        {
          fin >> string1 >> string2 >> string3;

          Indices.push_back((unsigned int)(string1[0]-'0'));
          Indices.push_back((unsigned int)(string2[0]-'0'));
          Indices.push_back((unsigned int)(string3[0]-'0'));
        }
      }
  fin.close();
}
```

### Rotation and Spinning
Below is the code that spins the object 
```bash
 angle += dt * M_PI/1000;
model = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));

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

## ATTENTION
To change the object you must change the following line in getObj() which is implemented in object.cpp
```bash
  fin.open( "../objects/boxR.obj" );

  		to

  fin.open( "../objects/box_open.obj" );
```



