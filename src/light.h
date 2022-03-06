#ifndef LIGHT_H
#define LIGHT_H

#include "utilities.h"
#include "triangle.h"

typedef struct Light
{
    double x;
    double y;
    double z;
    double intensity;
    SDL_Color color;
} Light;

void computeLight(Light light, Triangle* mesh);

#endif