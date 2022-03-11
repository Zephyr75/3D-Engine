#ifndef MESH_H
#define MESH_H

#include "utilities.h"
#include "triangle.h"

typedef struct Mesh
{
    Triangle* faces;
    int length;
} Mesh;

void drawMesh(SDL_Renderer* renderer, Mesh* mesh, Camera camera);

#endif