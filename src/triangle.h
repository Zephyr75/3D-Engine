#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"
#include "camera.h"
#include "SDL.h"
#include <stdio.h>
#include <math.h>
#include "pixel.h"

typedef struct Triangle
{
    Vertex first;
    Vertex second;
    Vertex third;
} Triangle;

void drawTriangle(SDL_Renderer* renderer, Triangle triangle, Camera camera, Screen* screen);

#endif