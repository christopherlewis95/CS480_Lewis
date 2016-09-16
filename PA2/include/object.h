#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "graphics_headers.h"
#include <SDL2/SDL.h>

class Object
{
  public:
    Object();
    ~Object();
    void Update(unsigned int dt, unsigned int passUInt);
    void Render();

    glm::mat4 GetModel();

  private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;
    bool spacePressed;

    float angle;
    float vertSpin;
};

#endif /* OBJECT_H */
