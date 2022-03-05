#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"
#include "camera.h"
#include "pixel.h"

#include "utilities.h"

typedef struct Triangle
{
    Vertex first;
    Vertex second;
    Vertex third;
    SDL_Color color;
} Triangle;

void drawTriangle(SDL_Renderer* renderer, Triangle triangle, Camera camera, Screen* screen);

Vertex getAverage(Triangle triangle);

#endif