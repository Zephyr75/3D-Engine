#ifndef VERTEX_H
#define VERTEX_H

#include "utilities.h"
#include "camera.h"

typedef struct Vertex
{
    double x;
    double y;
    double z;
    SDL_Color baseColor;
    SDL_Color color;
} Vertex;

SDL_Point get2DCoordinates(Vertex vertex, Camera camera);

#endif