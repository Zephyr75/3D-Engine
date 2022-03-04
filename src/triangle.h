#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"

typedef struct Triangle
{
    Vertex first;
    Vertex second;
    Vertex third;
} Triangle;

void drawTriangle(SDL_Renderer* renderer, Triangle triangle);

#endif