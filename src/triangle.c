#include "triangle.h"
#include "SDL.h"
#include "vertex.h"
#include <stdio.h>
#include <math.h>

#define LOW(y) function((double) y, points[0], points[1])
#define HIGH(y) function((double) y, points[1], points[2])
#define FULL(y) function((double) y, points[0], points[2])
#define ABS(a) (a > 0 ? a : -a)

double function(double y, SDL_Point first, SDL_Point second)
{
    double fX = (double) first.x;
    double fY = (double) first.y;
    double sX = (double) second.x;
    double sY = (double) second.y;
    return fX + (sX - fX) * ABS((fY - y)/(fY - sY));
}

int compare (const void* first, const void* second) 
{
    SDL_Point f = *((SDL_Point*)first);
    SDL_Point s = *((SDL_Point*)second);
    if (f.y > s.y) return 1;
    if (f.y < s.y) return -1;
    return 0;
}

void drawTriangle(SDL_Renderer* renderer, Triangle triangle){
    SDL_Point* points = calloc(3, sizeof(SDL_Point));
    points[0] = get2DCoordinates(triangle.first);
    points[1] = get2DCoordinates(triangle.second);
    points[2] = get2DCoordinates(triangle.third);

    qsort (points, 3, sizeof(SDL_Point), compare);

    int first, second;

    for (size_t i = points[0].y; i < points[1].y; i++)
    {
        first = LOW(i);
        second = FULL(i);
        SDL_RenderDrawLine(renderer, first, i, second, i);
    }
    for (size_t i = points[1].y; i <= points[2].y; i++)
    {
        first = floor(HIGH(i));
        second = floor(FULL(i));
        SDL_RenderDrawLine(renderer, first, i, second, i);
    }
    
    free(points);
}