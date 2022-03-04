#ifndef VERTEX_H
#define VERTEX_H

#include "SDL.h"

typedef struct Vertex
{
    int x;
    int y;
    int z;
} Vertex;

SDL_Point get2DCoordinates(Vertex vertex);

#endif