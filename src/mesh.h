#ifndef MESH_H
#define MESH_H

#include "utilities.h"
#include "triangle.h"

typedef struct Mesh
{
    Triangle* triangles;
    Vertex* vertices;
    int trianglesCount;
    int verticesCount;
} Mesh;

void drawMesh(SDL_Renderer* renderer, Mesh* mesh, Camera camera);

void clearMesh(Mesh* mesh);

#endif