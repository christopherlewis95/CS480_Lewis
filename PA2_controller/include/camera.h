#ifndef CAMERA_H
#define CAMERA_H

#include "graphics_headers.h"
#include <SDL2/SDL.h>
//#include "graphics.h"

class Camera
{
  public:
    Camera();
    ~Camera();
    bool Initialize(int w, int h);
    glm::mat4 GetProjection();
    glm::mat4 GetView();
    void updateCamera( unsigned int toggleNum );
  
  private:
    glm::mat4 projection;
    glm::mat4 view;

    float posX;
    float posY;
    float posZ;

    float focusX;
    float focusY;
    float focusZ;
};

#endif /* CAMERA_H */
