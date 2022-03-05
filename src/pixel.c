#include "pixel.h"

void setPixel(Screen* screen, int x, int y, SDL_Color color, double distance){
    screen[x * RESOLUTION_X + y]->color = color;
    screen[x * RESOLUTION_X + y]->distance = distance;
}