#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"
#include "camera.h"

#include "utilities.h"

typedef struct Triangle
{
    Vertex first;
    Vertex second;
    Vertex third;
    SDL_Color color;
} Triangle;

void drawTriangle(SDL_Renderer* renderer, Triangle triangle, Camera camera);

void drawWireframeTriangle(SDL_Renderer* renderer, Triangle triangle, Camera camera);

Vertex getAverage(Triangle triangle);

#endif