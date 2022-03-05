#ifndef PIXEL_H
#define PIXEL_H

#include "SDL.h"
#include "constants.h"

typedef struct Pixel
{
    SDL_Color color;
    double distance;
} Pixel;

typedef Pixel* Screen;

void setPixel(Screen* screen, int x, int y, SDL_Color color, double distance);

#endif