#include "object.h"


Object::Object()
{  

  //Vertices = new Vertices[];
  getObj();

  // The index works at a 0th index
  for(unsigned int i = 0; i < Indices.size(); i++)
  {
    Indices[i] = Indices[i] - 1;
  }

  angle = 0.0f;

  glGenBuffers(1, &VB);
  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

  glGenBuffers(1, &IB);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
}

Object::~Object()
{
  Vertices.clear();
  Indices.clear();
}

void Object::Update(unsigned int dt)
{
  angle += dt * M_PI/1000;
  model = glm::rotate(glm::mat4(1.0f), (angle), glm::vec3(0.0, 1.0, 0.0));
}

glm::mat4 Object::GetModel()
{
  return model;
}

void Object::Render()
{
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, VB);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);

  glDrawElements(GL_TRIANGLES, Indices.size(), GL_UNSIGNED_INT, 0);

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
}

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
        fin >> s;

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

