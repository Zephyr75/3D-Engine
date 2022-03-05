#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"
#include "camera.h"

typedef struct Triangle
{
    Vertex first;
    Vertex second;
    Vertex third;
} Triangle;

void drawTriangle(SDL_Renderer* renderer, Triangle triangle, Camera camera);

#endif